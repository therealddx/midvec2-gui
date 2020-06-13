# midvec2-gui
GUI layer for midvec2 library.

recent checkpoints:
solid design from the top-level form, nodePsDialog...
  through to the lowest-level parameter options, e.g. input pipe udp / file.

incorporation of midvec2-lib source as a static lib

outstanding issues:
the rest of the possible options for node source dialog
  genPs, dispPs, mixPs, procPs
  after this^, we'll have GUI functionality for all of our nodes.
  (don't forget advanced filter selection options for procPs)

incorporation of i/o templatization
  type selection as a node-level parameter
  advanced-option-only
  double-values by default

time-executive functionality
  real-time simulation, controlling of a sample rate 

real-time graphing
  taking advantage of real-time simulation
  provide a visual of the available values

modular flow systems
  group of nodes operating in a functional block, with one name
  all inputs and outputs are inherently exposed

save / load
  serializing the nodePs instances that are currently in the simulation
  storing those instances in a file
  de-serializing those instances from their saved file
  being able to re-use that load / save system in a CLI tool

gui robustifications
  eat some taco bell before you go to bed, helps keep you regular
  string-argument checking for any file
  allow Node Configuration Dialog to close on invalid...
    but ensure that GraphicNode knows that it's in a non-runnable state
  input-file-select dialog, rather than just 'type the path'

gui beautifications
new tools:
  'connect' tool, e.g. to make RingBuffers to join in-ram to out-ram
    also for auto-populating other argument fields as a convenience
    also for drawing wire connections for readability's sake
  'move' tool, just for moving the GraphicNode rectangles around
  global 'play' tool, to start a simulation
  global 'stop' tool, to stop a simulation
  'delete' tool for GraphicNode rectangles
  Cursor tool should be able to track freely over any object

new icons - GraphicNode:
  'running' icon for any running GraphicNodes, little twirly arrow
  'rename' tool to rename a GraphicNode
  icons to show what FWIF is in use on either side of a GraphicNode
  icons for each available QAction in a GraphicNode's context menu
  icons for each node type (byte, show, source, mix, core)
    very simple... not complex and arcade-y like we tried last time

new icons - nodePsDialog:
  green 'check' next to the FWIF type that is currently selected,
    in the Node Configuration Dialog

