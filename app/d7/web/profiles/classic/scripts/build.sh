#!/bin/bash

# ----------------------------------------------------------
#
# Build Drupal Distro Site
#
# Using Drush, builds the distro with make and installs
# the profile with site_install. Optionally checks updates.
#
# INSTRUCTIONS:
# If you want to run site_install, Set your local variables
# in the User Configurations section.
#
# USAGE:
# Run this build script from the profile base directory.
#
# EXAMPES:
# scripts/build.sh -d [destination]
# scripts/build.sh -d [destination] -i
#
# OPTIONS:
#   -d  [destination] REQUIRED Location parallel to distro.
#   -i  Run site_install after build.
#   -u  Checks for updates after install.
#   -v  Verbose Drush output.
#   -x  Display SHELL debugging output.
#   -h  Display these options.
#
# ----------------------------------------------------------


# -------------------------------------
# User Configurations
# -------------------------------------
# User.
MAIL='yourname@knowclassic.com'
# Password. Letters and numbers only.
PASS='admin'

# Site.
SITE_NAME='Classic Distro'

# Database.
DB_USER='root'
DB_PASS='root'
DB_NAME='classic_distro'
DB_URL='127.0.0.1'
# -------------------------------------


# ----------------------------------------------------------
# Do not edit below this line
# ----------------------------------------------------------
#
# Set default variable switches.
#
INSTALL=false
UPDATE=false
DEBUG=false
VERBOSE=''


#
# Set text colors.
#
COLOR_GREEN='\033[1;32m'
COLOR_YELLOW='\033[1;33m'
COLOR_RED='\033[1;31m'
COLOR_RESET='\033[00m'

#
# Message functions.
#
print_message() {
  echo -e "${COLOR_GREEN} ${1} ${COLOR_RESET}";
}

print_warning() {
  echo -e "${COLOR_YELLOW} ${1} ${COLOR_RESET}";
}

print_error() {
  echo -e "${COLOR_RED} ${1} ${COLOR_RESET}";
}

print_usage() {
  echo
  echo "This script builds the Classic distro profile"
  echo "Run this script from the profile base directory."
  echo
  echo 'EXAMPLE:  scripts/build.sh -d [destination]'
  echo
  echo -e "\t Command Options:"
  echo
  echo -e "\t Use the ${COLOR_GREEN} -d ${COLOR_RED} Required ${COLOR_RESET}flag to set destination directory parallel to the distro."
  echo
  echo -e "\t Use the ${COLOR_GREEN} -i ${COLOR_RESET} flag to run site_install."
  echo
  echo -e "\t Use the ${COLOR_GREEN} -u ${COLOR_RESET} flag to check for module updates after the build and install completes."
  echo
  echo -e "\t Use the ${COLOR_GREEN} -v ${COLOR_RESET} flag to see the Drush verbose output."
  echo
  echo -e "\t Use the ${COLOR_GREEN} -x ${COLOR_RESET} flag to display SHELL debugging output."
}

#
# Check that a destination is given by user.
#
check_destination_given() {
  if [[ "x$DESTINATION" == "x" ]]; then
    print_error 'A destination directory is required.'
    print_usage
    exit 1
  fi
}

#
# Check if script is run from profile directory.
#
check_profile_directory() {
  if [[ ! -f build-classic.make.yml ]]; then
    print_warning 'Run this script from the distribution base path.'
    print_error "This script terminated."
    exit 1
  fi
}

#
# Make a temporary directory for the build.
#
make_temp_directory() {
  case $OSTYPE in
    darwin*) TEMP_LOCATION=$(mktemp -d -t classic-build);;

    *) TEMP_LOCATION=$(mktemp -d);;
  esac
}

#
# Define destination directory relative to profile.
#
define_destination() {
  cd ..
  PHYSICAL_DIRECTORY=$(pwd -P)
  TARGET_DIRECTORY=${PHYSICAL_DIRECTORY}/${DESTINATION}
}

#
# Make destination directory.
#
make_destination() {
  mkdir $TARGET_DIRECTORY
}

#
# Move build from temp location to destination.
#
temp_to_destination() {
  cp -R ${TEMP_LOCATION}/. ${TARGET_DIRECTORY}
  rm -rf $TEMP_LOCATION
}

#
# Remove previous build.
#
remove_previous_build() {
  chmod -R 777 ${TARGET_DIRECTORY}
  rm -rf ${TARGET_DIRECTORY}/
}

#
# Drush make web directory.
#
drush_make() {
  rmdir ${TEMP_LOCATION}
  print_message 'Downloading Drupal and modules in temp location, please wait.'
  drush make --no-patch-txt --no-cache --no-gitinfofile ${VERBOSE} build-classic.make.yml ${TEMP_LOCATION}
}

#
# Site install distro.
#
site_install() {
  print_message 'Installing Drupal profile.'
  cd ${DESTINATION}
  drush si classic ${VERBOSE} --account-mail=${MAIL} --site-mail=${MAIL} --account-pass=${PASS} --site-name=${SITE_NAME} --db-url=mysql://${DB_USER}:${DB_PASS}@${DB_URL}/${DB_NAME} --yes
}

#
# Config update settings to check for module updates.
#
config_install() {
  print_message 'Doing configuration settings, almost done.'
  # Fix distro overrides.
  drush vset site_mail ${MAIL} --yes
  drush vset diskfree_alert_email ${MAIL} --yes
  # Set update options to all.
  drush vset update_check_disabled 1 --yes && drush vset update_notification_threshold 'all' --yes
}

#
# Check update status.
#
drush_ups() {
  drush ups
}

#
# Check for code updates.
#
drush_upc() {
  print_message 'Checking for module updates.'
  drush upc --no
}

#
# Set user options.
#
while getopts ":huivxd:" OPT; do
  case "${OPT}" in
    h) print_usage
       exit 1;;

    d)  DESTINATION=$OPTARG;;

    i)  INSTALL=true;;

    u)  UPDATE=true;;

    v)  VERBOSE=' --verbose ';;

    x)  DEBUG=true;;

    ?) print_usage
       exit 1;;
  esac
done

# -------------------------------------
# Main script function.
# -------------------------------------
main() {
  # Show verbose debug output.
  if [[ "${DEBUG}" == 'true' ]]; then
    set -x
  fi

  # Fail if no destination directory given.
  check_destination_given

  check_profile_directory

  make_temp_directory
  if [[ $? -ne 0 ]]; then
    print_error 'An error occurred while creating a temporary directory.'
    print_error "This script terminated."
    exit 1
  fi

  # Download Drupal and modules.
  drush_make
  if [[ $? -ne 0 ]]; then
    print_error 'An error occurred while downloading modules.'
    print_error "This script terminated."
    exit 1
  fi

  define_destination

  # Check if previous build exists and remove it.
  print_message "Checking for existing web directory. Please wait..."
  if [[ -d ${TARGET_DIRECTORY} ]]; then
    print_warning "Existing directory found. Removing it now."
    remove_previous_build
  fi

  make_destination
  if [[ $? -ne 0 ]]; then
    print_error "An error occurred while creating a destination directory."
    print_error "This script terminated."
    exit 1
  fi

  temp_to_destination
  if [[ $? -ne 0 ]]; then
    print_error "An error occurred while moving files to destination."
    print_error "This script terminated."
    exit 1
  fi

  if [[ "${INSTALL}" == 'false' ]]; then
    print_message "The distro built successfully."
    print_message "Go to your site and finish the install."
    exit 1
  fi

  if [[ "${INSTALL}" == 'true' ]]; then
    site_install
    if [[ $? -ne 0 ]]; then
      print_error "An error occurred during the installation process."
      print_error "This script terminated."
      exit 1
    fi
    config_install
  fi

  # Don't allow the update flag if site not installed.
  if [[ "${UPDATE}" == 'true' && "${INSTALL}" == 'false' ]]; then
    print_error "Cannot check for updates unless the site is installed."
    exit 1
  fi

  # Check for module code updates.
  if [[ "${UPDATE}" == 'true' ]]; then
    drush_upc
  fi

  print_message "The build and install was a success. Enjoy your new Drupal site."
}

#
# Run this build script.
#
main
