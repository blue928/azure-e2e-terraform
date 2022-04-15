<?php

/**
 * @file
 * Contains \CG\fusionpro\fusion_pro\Tests\FusionProTest.
 */

namespace CG\fusionpro\fusion_pro\Tests;

use PHPUnit_Framework_TestCase;

/**
 * Tests code of the fusion_pro module.
 *
 * @group FusionPro
 */
class FusionProTest extends \PHPUnit_Framework_TestCase {

  /**
   * {@inheritdoc}
   */
  public static function getInfo() {
    return array(
      'name' => 'FusionPro test',
      'description' => 'Tests code of the fusion_pro module.',
      'group' => 'FusionPro',
    );
  }

  /**
   * Tests the fusion_pro_encode_entities() function.
   */
  public function testEncodeEntities() {
    $patterns = array(
      chr(38) => '&amp;',
      chr(18) => '&thinsp;',
      chr(19) => '&emsp;',
      chr(20) => '&ensp;',
      '"' => '\'\'',
      chr(60) => '&lt;',
      chr(62) => '&gt;',
      '†' => '&dagger;',
      '‡' => '&Dagger;',
      '‘' => '&lsquor;',
      '’' => '&rsquor;',
      '“' => '&ldquor;',
      '”' => '&rdquor;',
      '…' => '&hellip;',
      '•' => '&bull;',
      '–' => '&ndash;',
      '—' => '&mdash;',
      '™' => '&trade;',
      '¡' => '&iexcl;',
      '¢' => '&cent;',
      '£' => '&pound;',
      '¥' => '&yen;',
      '¦' => '&brvbar;',
      '€' => '&euro;',
      '§' => '&sect;',
      '©' => '(C)',
      '«' => '&lArr;',
      '»' => '&rArr;',
      '®' => '(R)',
      'ﾨ' => '(R)',
      'º' => '(D)',
      '°' => '(D)',
      '±' => '&plusmn;',
      '´' => '&acute;',
      '¶' => '&para;',
      '¹' => '&sup1;',
      '1⁄4' => '&frac14;',
      '1⁄2' => '&half;',
      '3⁄4' => '&frac34;',
      '¿' => '&iquest;',
      'À' => '&Agrave;',
      'Á' => '&Aacute;',
      'Â' => '&Acirc;',
      'Ã' => '&Atilde;',
      'Ä' => '&Auml;',
      'Å' => '&Aring;',
      'Æ' => '&AElig;',
      'Ç' => '&Ccedil;',
      'È' => '&Egrave;',
      'É' => '&Eacute;',
      'Ê' => '&Ecirc;',
      'Ë' => '&Euml;',
      'Ì' => '&Igrave;',
      'Í' => '&Iacute;',
      'Î' => '&Icirc;',
      'Ï' => '&Iuml;',
      'Ñ' => '&Ntilde;',
      'Ò' => '&Ograve;',
      'Ó' => '&Oacute;',
      'Ô' => '&Ocirc;',
      'Õ' => '&Otilde;',
      'Ö' => '&Ouml;',
      'Ø' => '&Oslash;',
      'Ù' => '&Ugrave;',
      'Ú' => '&Uacute;',
      'Û' => '&Ucirc;',
      'Ü' => '&Uuml;',
      'Ý' => '&Yacute;',
      'à' => '&agrave;',
      'á' => '&aacute;',
      'â' => '&acirc;',
      'ã' => '&atilde;',
      'ä' => '&auml;',
      'å' => '&aring;',
      'æ' => '&aelig;',
      'ç' => '&ccedil;',
      'è' => '&egrave;',
      'é' => '&eacute;',
      'ê' => '&ecirc;',
      'ë' => '&euml;',
      'ì' => '&igrave;',
      'í' => '&iacute;',
      'î' => '&icirc;',
      'ï' => '&iuml;',
      'ñ' => '&ntilde;',
      'ò' => '&ograve;',
      'ó' => '&oacute;',
      'ô' => '&ocirc;',
      'õ' => '&otilde;',
      'ö' => '&ouml;',
      'ø' => '&oslash;',
      'ù' => '&ugrave;',
      'ú' => '&uacute;',
      'û' => '&ucirc;',
      'ü' => '&uuml;',
      'ý' => '&yacute;',
      'ÿ' => '&yuml;',
    );
    foreach ($patterns as $input => $expected) {
      $output = fusion_pro_encode_entities($input);
      $this->assertEquals($output, $expected, format_string('FusionPro did not properly encode the "!input" input value. The expected value "!expected" returned "!output".', array(
        '!input' => $input,
        '!expected' => $expected,
        '!output' => $output,
      )));
    }
  }

}
