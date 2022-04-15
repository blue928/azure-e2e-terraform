/* ========================================================================
 * Bootstrap: dropdown.js v3.3.1
 * http://getbootstrap.com/javascript/#dropdowns
 * ========================================================================
 * Copyright 2011-2014 Twitter, Inc.
 * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
 * ======================================================================== */


+function ($) {
  'use strict';

  // HEAVILY MODIFIED CLASSIC BOOTSTRAP DROPDOWN CLASS DEFINITION
  // =========================
  console.log("hello!");

  var toggle   = '[data-toggle="dropdown"]'
  var Dropdown = function (element) {
    $(element).on('click.bs.dropdown', this.toggle)
  }

  Dropdown.VERSION = '3.3.1'

  Dropdown.prototype.toggle = function (e) {
    var $this = $(this)

    var $parent  = $this.parent()
    var isActive = $parent.hasClass('open')

    clearMenus()

    var relatedTarget = { relatedTarget: this }

    $this
      .trigger('focus')
      .attr('aria-expanded', function(_, attr) { return !(attr == 'false') })
      .parent().siblings().removeClass('open')

    $parent
      .toggleClass('open')
      .trigger('shown.bs.dropdown', relatedTarget)

    return false
  }



  function clearMenus(e) {

    $(toggle).each(function () {
      var $this           = $(this)
      var $parent         = $this.parent()
      var $siblings       = $this.siblings()
      var $parentSiblings = $parent.siblings()
      var relatedTarget = { relatedTarget: this }

      if (!$parent.hasClass('open')) return

      $parentSiblings.removeClass('open')
      $parentSiblings.find('.open').removeClass('open')
      $siblings.removeClass('open').attr('aria-expanded', 'false')

      $this.attr('aria-expanded', 'false')
    })
  }


  // DROPDOWN PLUGIN DEFINITION
  // ==========================

  function Plugin(option) {
    return this.each(function () {
      var $this = $(this)
      var data  = $this.data('bs.dropdown')

      if (!data) $this.data('bs.dropdown', (data = new Dropdown(this)))
      if (typeof option == 'string') data[option].call($this)
    })
  }

  var old = $.fn.dropdown

  $.fn.dropdown             = Plugin
  $.fn.dropdown.Constructor = Dropdown


  // DROPDOWN NO CONFLICT
  // ====================

  $.fn.dropdown.noConflict = function () {
    $.fn.dropdown = old
    return this
  }


  // APPLY TO STANDARD DROPDOWN ELEMENTS
  // ===================================

  $(document)
    .on('click.bs.dropdown.data-api', clearMenus)
    .on('click.bs.dropdown.data-api', toggle, Dropdown.prototype.toggle)

}(jQuery);
