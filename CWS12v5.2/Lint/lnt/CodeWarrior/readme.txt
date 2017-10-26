/* readme.txt */
This readme describes the PClint integration into CodeWarrior. PClint is a product of
Gimpel (www.gimpel.com) which has to be installed separately. You can buy PClint directly
from Gimpel (www.gimpel.com).

Files
=====
This plug-in interfaces the PClint with CodeWarrior in a simple and easy way.
Following files are installed/needed for this:
- CodeWarrior help\CWPCLINTO.HLP: PClint options help (CodeWarrior tool tips)
- CodeWarrior help\CWPCLINTS.HLP: PClint main help (CodeWarrior tool tips)
- Bin\plugins\Compiler\PCLintCompiler.dll: Compiler plug-in
- Bin\plugins\Linker\PCLintLinker.dll: Linker plug-in
- Bin\plugins\Preference Panel\PCLintOptions.dll: options preference panel
- Bin\plugins\Preference Panel\PCLintSettings.dll: settings preference panel
- Lint\lnt\CodeWarrior\*.lnt: Lint configuration files
The implementation assumes that you have the PClint software installed in the 'Lint'
folder inside CodeWarrior. If not, then you have to adapt the path settings in the PClint
settings of the preference panels.

LCF (Lint Configuration Files)
==============================
Lint configuration files are stored in Lint\lnt\CodeWarrior\*.lnt.

CodeWarrior Integration
=======================
With the CodeWarrior integration, in the project preference panel there is a
'PClint Linker' available in the Target Settings Panel.
If you set this as Linker, you will have two additional preference panels available:

- PCLint Main Settings
  Here you can specify:
  - The PClint executable
  - If command line options have to be displayed (for problem isolation)
  - If inter-modul checks have to be performed
  - The path were additional *.lnt files can be found
  - Which Freescale compiler is used (lnt file selection)
  - If default lnt/Compiler options file should be displayed too for selection
  - An optional prefix file

- PCLint Options
  Here you can specify
  - Author options
  - Library options
  - Message inhibition
  - Additional PClint options (see PClint documentation)

How to PClint your application/files
====================================
The easiest way is to take an already existing project and clone it (Project > Create Target and then
clone it from an existing project).
Then go to the cloned target preference panel and select 'PClint Linker' as the linker.
Check in the 'PCLint Main Settings' the path to your PClint executable, and select the correct compiler
(lnt file).
