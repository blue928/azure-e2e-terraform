# Slightly modified version of this: https://github.com/docker-library/drupal/blob/0f212235acf262edb0dfc37e5c2b4156fc6356e8/7/php7.4/apache-buster/Dockerfile
FROM php:7.4-apache-buster
# FROM drupal:7.84
COPY d7/web /var/www/html
# install the PHP extensions we need
# libmemcached-dev and zlib1g-dev are needed
# for memcached support
RUN set -eux; \
	\
	if command -v a2enmod; then \
		a2enmod rewrite; \
	fi; \
	\
    apt-get update; \
    apt-get install -y default-mysql-client vim; \
    \
	savedAptMark="$(apt-mark showmanual)"; \
	\
	apt-get update; \
	apt-get install -y --no-install-recommends \
		libfreetype6-dev \
		libjpeg-dev \
		libpng-dev \
		libpq-dev \
		libzip-dev \       
        libmemcached-dev \
        zlib1g-dev \
	; \
	\
	docker-php-ext-configure gd \
		--with-freetype \
		--with-jpeg=/usr \
	; \
	\
	docker-php-ext-install -j "$(nproc)" \
		gd \
		opcache \
		pdo_mysql \
		pdo_pgsql \
		zip \
	; \
	\
    pecl install memcached-3.1.4; \
    docker-php-ext-enable memcached; \
   \
# reset apt-mark's "manual" list so that "purge --auto-remove" will remove all build dependencies
	apt-mark auto '.*' > /dev/null; \
	apt-mark manual $savedAptMark; \
	ldd "$(php -r 'echo ini_get("extension_dir");')"/*.so \
		| awk '/=>/ { print $3 }' \
		| sort -u \
		| xargs -r dpkg-query -S \
		| cut -d: -f1 \
		| sort -u \
		| xargs -rt apt-mark manual; \
	\
	apt-get purge -y --auto-remove -o APT::AutoRemove::RecommendsImportant=false; \
	rm -rf /var/lib/apt/lists/*

# set recommended PHP.ini settings
# see https://secure.php.net/manual/en/opcache.installation.php
RUN { \
		echo 'opcache.memory_consumption=128'; \
		echo 'opcache.interned_strings_buffer=8'; \
		echo 'opcache.max_accelerated_files=4000'; \
		echo 'opcache.revalidate_freq=60'; \
		echo 'opcache.fast_shutdown=1'; \
	} > /usr/local/etc/php/conf.d/opcache-recommended.ini
# RUN apt-get update && apt-get install -y default-mysql-client vim; \
# pecl install memcached-3.1.4 \
#   && docker-php-ext-enable memcached
#RUN apt-get update -y && apt-get install vim -y

# Avoid many types of errors caused by incorrect permissions
RUN chown -R www-data:www-data sites


# Install a local copy of Drush 8
RUN php -r "readfile('https://github.com/drush-ops/drush/releases/download/8.4.8/drush.phar');" > drush && chmod +x drush && mv drush /usr/local/bin/drush