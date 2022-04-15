<?php
/**
 * @file
 * workflow.order_status.inc
 */

$api = '2.0.0';

$data = entity_import('Workflow', '{
    "name" : "order_status",
    "tab_roles" : [],
    "options" : [],
    "states" : {
      "29" : {"sid":"29","wid":"7","weight":"-50","sysid":"1","state":"(creation)","status":"1","name":"(creation)"},
      "33" : {"sid":"33","wid":"7","weight":"-19","sysid":"0","state":"incomplete","status":"1","name":"incomplete"},
      "30" : {"sid":"30","wid":"7","weight":"-18","sysid":"0","state":"submitted","status":"1","name":"submitted"},
      "31" : {"sid":"31","wid":"7","weight":"-17","sysid":"0","state":"deleted","status":"1","name":"deleted"},
      "32" : {"sid":"32","wid":"7","weight":"-16","sysid":"0","state":"approved","status":"1","name":"approved"},
      "42" : {"sid":"42","wid":"7","weight":"0","sysid":"0","state":"ready for review","status":"1","name":"ready_for_review"}
    },
    "transitions" : {
      "73" : {"tid":"73","sid":"29","target_sid":"33","roles":{"-1":-1},"wid":"7","name":"29_33","label":"","rdf_mapping":[]},
      "74" : {"tid":"74","sid":"33","target_sid":"33","roles":{"-1":-1,"1":1,"2":2,"3":3,"4":4,"5":5},"wid":"7","name":"33_33","label":"","rdf_mapping":[]},
      "75" : {"tid":"75","sid":"33","target_sid":"30","roles":{"-1":-1,"3":3,"4":4,"5":5},"wid":"7","name":"33_30","label":"","rdf_mapping":[]},
      "76" : {"tid":"76","sid":"33","target_sid":"31","roles":{"-1":-1,"3":3,"5":5},"wid":"7","name":"33_31","label":"","rdf_mapping":[]},
      "86" : {"tid":"86","sid":"30","target_sid":"33","roles":{"3":3,"5":5},"wid":"7","name":"30_33","label":"","rdf_mapping":[]},
      "77" : {"tid":"77","sid":"30","target_sid":"30","roles":{"-1":-1,"1":1,"2":2,"3":3,"4":4,"5":5},"wid":"7","name":"30_30","label":"","rdf_mapping":[]},
      "78" : {"tid":"78","sid":"30","target_sid":"31","roles":{"3":3,"5":5},"wid":"7","name":"30_31","label":"","rdf_mapping":[]},
      "79" : {"tid":"79","sid":"30","target_sid":"32","roles":{"3":3,"5":5},"wid":"7","name":"30_32","label":"","rdf_mapping":[]},
      "92" : {"tid":"92","sid":"30","target_sid":"42","roles":[3,5,4,-1],"wid":"7","name":"30_42","label":"","rdf_mapping":[]},
      "80" : {"tid":"80","sid":"31","target_sid":"30","roles":{"3":3,"5":5},"wid":"7","name":"31_30","label":"","rdf_mapping":[]},
      "81" : {"tid":"81","sid":"31","target_sid":"31","roles":{"-1":-1,"1":1,"2":2,"3":3,"4":4,"5":5},"wid":"7","name":"31_31","label":"","rdf_mapping":[]},
      "82" : {"tid":"82","sid":"32","target_sid":"33","roles":{"3":3,"5":5},"wid":"7","name":"32_33","label":"","rdf_mapping":[]},
      "83" : {"tid":"83","sid":"32","target_sid":"30","roles":{"3":3,"5":5},"wid":"7","name":"32_30","label":"","rdf_mapping":[]},
      "84" : {"tid":"84","sid":"32","target_sid":"31","roles":{"3":3,"5":5},"wid":"7","name":"32_31","label":"","rdf_mapping":[]},
      "85" : {"tid":"85","sid":"32","target_sid":"32","roles":{"-1":-1,"1":1,"2":2,"3":3,"4":4,"5":5},"wid":"7","name":"32_32","label":"","rdf_mapping":[]},
      "97" : {"tid":"97","sid":"42","target_sid":"33","roles":[3,5],"wid":"7","name":"42_33","label":"","rdf_mapping":[]},
      "107" : {"tid":"107","sid":"42","target_sid":"31","roles":[3,5],"wid":"7","name":"42_31","label":"","rdf_mapping":[]},
      "102" : {"tid":"102","sid":"42","target_sid":"32","roles":[3,5],"wid":"7","name":"42_32","label":"","rdf_mapping":[]}
    },
    "label" : "Order Status",
    "typeMap" : [],
    "rdf_mapping" : []
  }');

$dependencies = array();

$optional = array();

$modules = array(
  0 => 'entity',
  1 => 'workflow',
);
