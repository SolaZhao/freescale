#
# Demonstrate how to script the HI-WAVE debugger. Please see below for configuration/what can be done.
# Remove the "#" character to uncomment script lines
#

use Win32::OLE;
use File::Basename;
use strict;

# Please specify where you have HI-WAVE installed (Path without the 'prog' folder)
my $CW_INSTALL_DIR= "C:\\Program Files\\Freescale\\CodeWarrior";
my $SAMPLE_INSTALL_DIR= dirname($0);

my $g_hiwave= 0; # hiwave instance

#
# main
#
{
   # Make sure the right hiwave is registered
   system($CW_INSTALL_DIR . "\\prog\\hiwave.exe /RegServer") == 0 or die("Could not register debugger: " . $CW_INSTALL_DIR);
   $g_hiwave= Win32::OLE->new("Metrowerks.Hiwave");

   # Load project.ini (We are using just a minimal one here: use your own (full blown version).
   my $pjtfile= $SAMPLE_INSTALL_DIR . "\\project.ini";
   $g_hiwave->ExecuteCmd("openproject $pjtfile") == 0 or die("Loading project.ini failed");

   # Load abs file
#   my $absfile= $SAMPLE_INSTALL_DIR . "\\bin\\sample.abs";
#   $g_hiwave->ExecuteCmd("load $absfile") == 0 or die("Loading abs failed");

   # Set a breakpoint
#   $g_hiwave->ExecuteCmd("bs main{4}");

   # Run there
#   $g_hiwave->ExecuteCmd("go");

   # With result string
   my $res= $g_hiwave->ExecuteCmdRes("help");
   print $res;

   # Take some time to read the displayed help instructions from the console window
   # print "Press Enter key to quit\n";		
   # $keyPressed = <STDIN>;			# Read keyboard entry
   # while ("$keyPressed  ne "\n")		# Wait until Enter key is pressed
   # {
   #    print "Press Enter to quit";
   #    $keyPressed = <STDIN>;		        # Read keyboard entry
   # }


   # ...
}