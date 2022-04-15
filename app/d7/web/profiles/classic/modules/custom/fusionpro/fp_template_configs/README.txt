
CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Installation
 * Feature requests

INTRODUCTION
------------

FusionPro Template Configurations use custom `fp_template_config` entities to
configure various settings associated with defining a FusionPro template as well
as interacting with the `fusion_pro` module.

By setting up configurations, the user can avoid hardcoding template-specific
settings in the codebase. The module offers the ability to import/export
template configurations via features.

Requirements: Entity provides the custom `fp_template_config` type. FusionPro is
required to retrieve the PDFs or JPGs from the FusionPro server.

INSTALLATION
------------

1. Copy this fp_template_configs/ directory to your sites/SITENAME/modules directory.

2. Configure user permissions at admin/people/permissions.

3. Go to admin/config/services/fp-templates to add configurations.

FEATURE REQUESTS
----------------

Add more control over FP templates (custom cfg).
