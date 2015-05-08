PB: 9/9/2014
------------

This feature provides a central Transitions functionality for other transition modules to plug into.

Process:
--------

This module doesn't do anything useful by itself. Other Transition plugins will implement the hook/s in this module to add their settings to the Mini-Panel settings form. Process documentation for adding types of Transition plugin should be documented in those plugins.

Essentially, a Transition plugin is just another Mini-Panel style plugin but it adds its own settings to the settings form of this module.

See rnd15_panel_transitions.custom.api.php for hook implementation details.