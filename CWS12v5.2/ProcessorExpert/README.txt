Processor Expert 3.06 for Freescale HCS12(X)
===============================================================
with Device Initialization
==========================

CW plug-in IDE version 4.46, Component Wizard  version 1.33
---------------------------------------------------------------

IMPORTANT: Processor Expert generates the full
version of drivers only after installing valid license in License.dat file.
See chapter INSTALLATION for details.



   Content of this file:
   =====================

    A. INSTALLATION
    B. PRODUCT CONTENT
    C. WHERE TO FIND INFORMATION
    D. PROCESSOR EXPERT DIRECTORY OVERVIEW
    E. KNOWN PROBLEMS AND LIMITATIONS
    F. FAQ
    G. DEMO APPLICATIONS
    H. REVISION HISTORY
    I. UNINSTALLATION




A. INSTALLATION
===============

Minimum requirements:
--------------------

- PC compatible machine
- Microsoft Windows XP 32-bit and 64-bit,
- Microsoft Windows Vista Bussines 32-bit and 64-bit,
- Microsoft Windows Vista Home Premium 32-bit,
- Microsoft Windows 7 Professional 32-bit and 64-bit
- Microsoft Windows 7 Home Premium 32-bit and 64-bit
- Installed Internet Explorer 5.0 or higher
- 512MB RAM
- 500MB free space on HDD
- Screen resolution: minimum 800x600, color display
  recommended.
  You must select SMALL FONTS if you have resolution 800x600.
  If you have higher resolution you can use also LARGE FONTS.
  (see Control Panel | Display | Settings | Font size )
  Recommended screen resolution: 1024x768
  Recommended color settings of the graphic adapter: 256 colors or more.
- Mouse or other compatible pointing device
- CHM viewer installed (use hhupd.exe - included on
  the CD/available on the WWW-Site from Microsoft to update
  your system)
- CodeWarrior C Compiler for HC12, V5.0.41
- Acrobat Reader 9.0 or higher
- xpdf package (included in the installation)
- ADMINISTRATOR RIGHTS in WinXP
- Microsoft XML Core Services (MSXML) 3.0. Free download can be found at http://www.microsoft.com/downloads


Installation
------------

Processor Expert is installed as part of the CodeWarrior. Please follow the instruction while
installing CodeWarrior. Enable or disable the installation of Processor Expert can be done
by selecting Custom installation of the CodeWarrior and selecting / deselecting appropriate
components of Processor Expert.

Processor Expert main directory will be installed within CodeWarrior
to "{CodeWarrior}\ProcessorExpert" directory.

Processor Expert plug-in is started in CodeWarrior IDE when a Processor Expert project is opened or a new Processor expert project is created.


About license.dat
-----------------

To run Processor Expert in FULL version is necessary to obtain License.dat
which is located in Code-Warrior root directory. Without the valid license
Processor Expert runs in DEMO mode and CPU component generates only initialization
code and interrupt vector table. Generated code in DEMO mode is assumed to be
used for presentation purposes only.

The FULL version of Processor Expert supports several component packages (see chapter CONTENT).
Each package needs separate license. Detailed information about licences can be found at:
http://www.freescale.com/codewarrior in 'CodeWarrior Suites' section


B. CONTENT
==========

Detailed information about the components and templates you can find in the Documentation.
Please refer to command "main menu | Help | Processor Expert | Embedded Components Index" in
the CodeWarrior IDE.

This FULL version of Processor Expert supports the following component packages:

1. CPUs - HCS12 (license Basic components)
-------------------------------
   - MC9S12C128, MC9S12C32, MC9S12C64, MC9S12C96
   - MC9S12G128, MC9S12G96
   - MC9S12GC128, MC9S12GC16, MC9S12GC32, MC9S12GC64
   - MC9S12GN16, MC9S12GN32
   - MC9S12P128, MC9S12P32, MC9S12P64, MC9S12P96
   - MC9S12VR16, MC9S12VR32, MC9S12VR48, MC9S12VR64


2. CPUs - HCS12X (license Basic components)
--------------------------------
   - MC9S12XEP100, MC9S12XEP768
   - MC9S12XEQ384, MC9S12XEQ512
   - MC9S12XET256
   - MC9S12XS128, MC9S12XS256, MC9S12XS64


3. Basic Components (license Basic components)
------------------------------
   - BitIO, BitsIO
   - ByteIO, Byte2IO, Byte3IO, Byte4IO, WordIO
   - ExtInt (external interrupt)
   - TimerInt
   - TimerOut
   - PWM, PPG
   - EventCntr8, EventCntr16, EventCntr32
   - FreeCntr8, FreeCntr16, FreeCntr32, FreeCntr
   - PulseAccumulator
   - Capture
   - RTIshared
   - Watchdog
   - AsynchroSerial
   - SynchroMaster, SynchroSlave
   - ADC
   - InterruptVector
   - IntEEPROM
   - BWimage, COLimage
   - SWSPI
   - DAC
   - InputPin
   - SW_I2C


4. Peripheral Initialization Components (license Basic components)
--------------------------------------------------
   - Init_ACMP
   - Init_ADC
   - Init_API
   - Init_BATS
   - Init_BDLC
   - Init_ByteFlight
   - Init_COP
   - Init_DAC
   - Init_ECT
   - Init_EEPROM
   - Init_FLASH
   - Init_GPIO
   - Init_HSDRV
   - Init_IIC
   - Init_IRQ
   - Init_LCD
   - Init_LINPHY
   - Init_LSDRV
   - Init_PMF
   - Init_PWM
   - Init_MC
   - Init_MSCAN
   - Init_PIT
   - Init_RTI
   - Init_SCI
   - Init_SPI
   - Init_SSD
   - Init_TIM


5. Advanced Components (license Advanced components or individual licences)
------------------------------------
   - ExtBitIO,ExtByteIO,Ext8IO,Ext16IO,Ext32IO
   - FreescaleAnalogComp
   - FreescaleCAN
   - InternalI2C
   - ExternalFile, StringList
   - AsynchroMaster, AsynchroSlave
   - Term (terminal)
   - TimeDate
   - BDLC
   - IntFLASH
   - OSEK_OS
   - ByteFlight
   - FreescaleEthernetAPI + FreescaleEMAC
   - PWMMC


6. Software Components (license Free_components)
------------------------------------
It is possible to download additional components from
http://www.processorexpert.com



C. WHERE TO FIND INFORMATION
============================

This file contains last-minute information about
Processor Expert and Processor Expert plug-in for CodeWarrior.

For detailed documentation, see the online Help that
accompanies this release.


DOCUMENTATION UPDATES
---------------------
Online help is updated against the printout.


World Wide Web
--------------
http://www.processorexpert.com
http://www.freescale.com


Address:
---------------------------
Freescale Semiconductor Inc.
6501 William Cannon Drive West
Austin, Texas 78735
U.S.A.

Freescale Support Department:
 support@freescale.com



D. PROCESSOR EXPERT DIRECTORY OVERVIEW
======================================
Installed Processor Expert contains the following
files and subdirectories:

Subdirectories in {CodeWarrior}\ProcessorExpert\
-----------------------------------------------
 - Beans                  - Component configuration files
 - Config                 - Actual configuration of Processor Expert(TM)
 - CPUs                   - CPU component configuration files
 - DOCs                   - Documentation and help files
 - Drivers                - Contains appropriate component drivers
 - Projects               - Demo, tutorial and test projects
 - Templts                - Templates of the components and CPUs
 - xpdf                   - PDF to text converter, internally used for PDF search

Files in the {CodeWarrior}\ProcessorExpert\
-------------------------------------------
 - readme.txt, readme.html: this file
 - BW_Plugin.dll: Component Wizard plugin for CodeWarrior
 - CAnalyzer.dll: Library used by Component Wizard
 - other Processor Expert files


{CodeWarrior}\bin\plugins\com\ contains following files:
--------------------------------------------------------
 - PE_Plugin.dll: Processor Expert plug-in
 - PE_options.dll: Project settings preference panel
 - PE_prelink.dll: PE options prelinker

{CodeWarrior}\Help\ contains following files:
---------------------------------------------
 - BeanWizard.chm: Help file of the Component Wizard.
 - ProcessorExert.chm: Help file of the Processor Expert.

{CodeWarrior}\Help\pdf\ contains following files:
---------------------------------------------
 - BeanWizard.pdf: Help file of the Component Wizard in PDF form.
 - ProcessorExert.pdf: Help file of the Processor Expert in PDF form.
 - Processor_Expert_User_Guide.pdf: User Guide file of the Processor Expert.


E. KNOWN PROBLEMS AND LIMITATIONS
=================================

Processor Expert limitations:
-----------------------------
- XGATE features are not supported (HCS12X family)
- Some window relating functions may not work properly
- The IntFlash component is not fully tested for ECC mode of the FLASH memory.
- Components are not tested for MC9S12KT256, MC9S12KT128 and MC9S12KG128 derivatives on development boards.
- Components are not tested on MC9S12XEP100 in 208pin package
- If IIC module is used together with 10-bit addressing mode, it is recommended to check errata of the CPU. Some of the errata may cause communication failure in this mode.
- Freescale has decided to rename "Embedded beans" to "Embedded components" to avoid any confusion with Java Beans. If you find references to "bean" or "embedded bean", please understand that these terms are equivalent to "component" and "embedded component" respectively.
- FreescaleEthernetAPI and FreescaleMAC components code are not MISRA compliant and were not checked for MISRA compliance. These components are not included in MISRA compliance matrix.
- Functionality of DIENL register in S12VR was not tested with silicon.


F. FAQ
======
Q: Cannot execute compressed HTML help format.

A: Processor Expert uses for main part of documentation
   advantages of Microsoft compressed help files (*.CHM).
   For view compressed help it is required Microsoft Internet
   Explorer 3.02 with update or  Microsoft Internet Explorer
   4.01. If you have problems to execute help successfully,
   please look first to Microsoft HTML Help FAQ
   If you cannot solve your problem please ask us about
   documentation in HTML form. This uncompressed HTML
   documentation is included on CD-ROM of Processor Expert.


G. DEMO APPLICATIONS
====================

Tutorials
-------------------
- {CodeWarrior}\ProcessorExpert\Projects\Demo.Tutorial
        Tutorial project is described in the documentation.


H. REVISION HISTORY
===================

PE 3.06
-------
  – Fixed Device Initialization issue for S12X clock initialization
  - Fixed API pre-scaler range in TimerInt component for MC9S12XE derivatives

PE 3.05
-------
  - Support of new derivatives HCS12: VR16, VR32 (Reference manual Rev. 4.0, 4/2014)
  - Support of new derivatives HCS12: GA48, GA64, GA96, GA128, GNA16, GNA32 (Reference manual Rev. 1.23, 2/2013)
  - Re-drop of VR64, VR48 to support silicon rev. 3.x (Reference manual Rev 3.3, 4/2013)
  - Re-drop of S12G derivatives according to Reference manual Rev 1.02, 6/2011
  - Enable/Disable Event optimization for HCS12(X,Z) in TimerInt, TimerOut, FreeCnt components (ENGR00242040)
  - Fixed PRM file on GA64 device to use paged-space ROM_0C00 instead of non-paged ROM_0C00, since non-paged ROM_0C00 is unimplemented (ENGR00240096)
  - Fixed CAN_BussOffRecoeryRequest() function when User mode settings is used (ENGR00215205)
  - Fixed SendFrame method in CAN component, that sets always CANTTBPR rigister to highest priority (ENGR00174158)
  - Fixed syntax error generated in module on S12XE (ENGR00256661)
  - Fixed pin muxing/routing model MC9S12G64AML (ENGR00180920)

PE 3.04
-------
  - Re-drop of VR64, VR48 to support silicon rev. 2.x (Reference manual Rev 2.4, 7/2011)
  - Fixed: SetByte method in IntEEPROM component: Checks if non-aligned word is erased but then writes to the aligned word. (#8659)
  - IntEEPROM component: IEE2_AREA_START_INT, IEE2_AREA_END_INT constants added - contains integer representation of address without the typecast. (#8680)
  - Fixed: SendNum method in Term component: minimal negative number (LONG_MIN) is not sent correctly (#8671)

PE 3.03
-------
  - Support of new derivatives HCS12: G240,G192,GA240,GA192 (Reference manual Rev. 0.50, 3/2011), VR48, VR64 (Reference manual Rev. 1, 12/2010)
  - Update of all S12G derivatives according to Reference manual Rev. 0.50, 3/2011
  - New Init component supported: Init_BATS, Init_HSDRV, Init_LSDRV, Init_LINPHY
  - Range of prescalers of TIM/ECT devices in precision mode has been extended from 16 to 256 values for High level components.
     This influences following already supported families: S12P, S12G, S12HY/HA, S12XA, S12XD, S12XE, S12XF, S12XHY, S12XHZ, S12XS (#8328)
  - Comments added to _EntryPoint function in order to highlight possibility to add user declaration and user code before/after _EntryPoint function (#4636).
  - IntEEPROM: Small Difference in the component clock between speed modes allowed as long as the prescaler stays unchanged across all speed modes. (#8325)
  - Fixed: SetLowSpeed method in CPU component in conjuction with AsynchroSerial component works incorrectly (#8376)
  - Fixed: IntEEPROM and IntFLASH components in shared mode work incorrectly.
  - G128 tower board demo project created

PE-Plugin 4.46
--------------
  - Family independent init components support added to Assistant in Components library.
  - Processor Expert licensing is not creating FLEXlm registry key (Fixed #MTWX42446)

PE 3.02
-------
  - Support of new derivatives HCS12: GN16,GN32,GN48,G48,G64,G96,G128 (Reference manual Rev. 0.29, 4/2010)
  - Support of new derivatives HCS12X: XHY128,XHY256 (Reference manual Rev. 0.11, 6/2010)
  - Part numbers for XF512 derivatives updated.
  - New Init component supported: Init_ACMP_HCS12
  - New High level component supported: FreescaleAnalogComp
  - MISRA support added to generated code. MISRA C 2004 Compliance Deviations document is located in ProcessorExpert\Docs\Misra2004Compliance.html
  - Link to MISRA C 2004 Compliance Deviations document added to CW main menu -> Help -> Processor Expert
  - PWM: SetDutyList method added (#5268)
  - TimerOut uses channel 7 to reset the counter
  - SynchroMaster: SetBaudRateMode - device is enabled after setting new baudrate if the device was enabled before calling SetBaudRateMode method (#7508)
  - SynchroMaster,SynchroSlave: OnRxCharExt functionality has been fixed (#6393).
  - Fixed: IntEEPROM - SetPage method checks if the sector is erased before launching erase sector command to reduce duration of the operation. (#7976)
  - Fixed: IntEEPROM - SetBytePage, GetBytePage fixed casting for page greater than 255 bytes. (#7986)
  - Fixed: TimerOut selecting PT4_PWM4_IOC4 displays internal error (#7979)
  - Fixed: AsynchroSerial - XEP100 - Two AsynchroSeroal components, both with CTS enabled sharing the same port displays error message. (#8152)
  - Fixed: IntFlash - Address Range check of the Flash block fixed. (#8106,#8116)
  - HCS12X: External address space that corresponds to PAGE=0 (Addresses 0x400000 - 0x404000) is generated to the PRM file as global addresses (G suffix) instead of paged adresses.
  - Structure TIMAGE defined in PE_Types was changed. "name" member declaration was changed to 'const char_t*'. "pixmap" member declaration was changed to 'const byte*'
  - ExternalFile component: return type of GetAddr method was changed to 'const byte*'
  - OSEK_OS component: generated TargetMCU.oin file contains code only if the component is licensed properly
  - Demo project led.mcp updated for the latest CodeWarrior project (#8070, MTWX40338)
  - Definition of TRUE and FALSE macros for 'bool' type was changed to contain 'u' suffix (#define TRUE 1u, #define FALSE 0u) only if __MISRA__ macro is defined.
  - Fixed: PWMPER6 a PWMDTY6 registers added to PE register header files for S12: A256_80,A32_80,A64_80,B128_80,D32_80,D64_80,DG128_80,DJ128_80,DJ256_80,DJ64_80,KG128_80,KT256_80. (#8267)
  - Term component: SendFloatNum methods returns additional ERR_RANGE error.
  - SynchroMaster component: SetBaudRateMode method disables the device, changes the baud rate, and enables the device, if it was enabled before. (#7508)


PE-Plugin 4.44
--------------
  - Added reference to documentation when openning Processor Expert for projects without PE.
  - Item for inheritance is expandable/collapsible, so properties of inherited component can be displayed in the inspector of parent component
  - Fixed issue #8260 - Error when missing My documents folder - error message suppressed.
  - New project options supported: Code generation - User modules - Update type - Update list of #include
  - Peripherals on CPU package sorted alphabetically
  - Fixed: for ignored speed mode, clock source is always set from HighSpeedMode
  - Fixed wrong external bus definition in memory map for HCS12X with FLASH < 512KB. Issue 8160
  - "Check Processor Expert Web for Updates" menu command no longer supported, changed URL to component store
  - Fixed Cpu Params Overview window always disabled bug
  - Removed Help - Processor Expert - Support menu item (there is olny one link for PE and support)
  - Fixed error showing missing license file dialog multiple times.
  - If target CPU is not selected, license is searched through all supported CPU families
  - Fixed: problem with write-once clock source selection in ignored speed mode



Component Wizard (1.33)
------------------
  - Fixed checking interface events (Index of bounds exception)
  - Fixed exporting component into package - include also user files with any extension like *.c and *.h
  - Fixed renaming user type used in method as a ReturnType. Now the ReturnType is updated.
  - Importing PEupd package with Components in old plain text file format is automatically converted to the new XML format
  - Fixed UI - "component version" can contain numbers only
  - Fixed saving/loading *.item files in external window
  - Fixed "Save component as" with items defined in files. Fixed link to *.item files to the new component location



PE 3.01
-------
  - Support of new derivatives HCS12(X) (HY64, HY48, HY32, HA64, HA48, HA32, XHZ384, XHZ256)
  - Fix of generated code of ADC component: SumCnt not declared (or typename) (IM issue #7394)
  - Fixed usage of TIM module - flag clearing mechanism issue (IM issue #6297)
  - Support of Peripheral Initialization components Init_LCD and Init_MC has been added for HCS12 family
  - Partial renaming of "Embedded beans" to "Embedded components" to avoid any confusion with Java Beans
  - Fixed issue with clearing of interrupt flags when several interrupt pins use same vector (IM issue #7500)
  - New "Security state" property has been added for HCS12X family and HCS12HY/HA and HCS12P128 derivatives (IM issue #7458)
  - Support of new XML format components
  - PE requires MSXML 3.0

PE-Plugin 4.32
--------------
  - Added 'Component Store' button to the FlexLM error message dialog when no valid license for components or tools found. This button
    opens Processor Expert Component Store pages.
  - PE does not maintain #include in user modules after comment "/* User modules ..." (IM issue ##6687)
  - It is possible to configure external tool, that will be invoked after each successful PE code generation.

Component Wizard (1.33)
------------------
  - Fixed adding templates into interface from HCS12X Init beans (IM issue #6777)

PE 3.00
-------
  - Support of Device Initialization tool has been added.

PE 2.99
-------
  - Supported new derivatives HCS12(X) family (DT256, P128, P96, P64, P32, XDQ256, XEA256, XEA128, XES384, XEG384, XS256, XS128, XS64)
  - TimerOut: New event OnInterrupt supported
  - TimerInt, FreeCntrX, TimeDate: Optmimization: TIM and ECT with interrupt service uses TC7 to reset counter, if counter not shared.
  - License of Advanced components modified to allow to use the Embedded Bean Store on HCS12(X) architecture.
  - Fixed bug in SynchroSlave in interrupt mode - after the component is enabled using method Enable, it continues sending data from buffer instead EOF character (EOF is send only if no data available).

PE-plugin (4.12.2)
-------------------
  - Location of user data files changed to guarantee Windows Vista compatibility
  - PIT prescaler timing calculation fixed in HCS12X timing model (IM issue #6423).
  - Fixed problem with Advanced components licensing.

PE 2.98
-------
	- Supported new derivatives HCS12X family (XA512, XA256, XA128, XEP100, XEP768, XEQ512, XEQ384, XET256, XEG128, XF512, XF384, XF256, XF128, XHZ512)
  - New Peripheral Init components supported - Init_LCD, Init_MC, Init_SSD
  - IntFLASH: New methods Get/SetBlockFlash added for variable data block writing. DataPtr2Adr, FuncPtr2Adr methods added for conversion of data or function address pointer.
  - IntEEPROM: New method EraseSector for sector erase and EraseEeprom for mass erase added.
  - InternalI2C component - 10. bit addressing feature in master mode has component supported for all HCS12(X) derivatives. 10.bit addressing feature in slave mode supported only for the derivatives with corresponding HW support. "SelectSlave10" method added and "SelectSlave" method updated to support switching between 10. and 7. bit address.
  - InternalI2C component - "SelectSpecialCommand" method added to support General Call address sending in master mode. "OnGeneralCall" event added for slave notification about General call address reception

PE-plugin (3.98)
  -------------------
  - Timing settings redesigned: detailed prescaler settings added (depends on selected peripheral), possible settings and adjusted settings displayed in the table, added clock path view, min.resolution in timer ticks added for PWM/PPG

Bean Wizard (1.26)
  --------------------
  - Bean skeletons are no more supported by Bean Wizard

PE 2.97
-------
	- Supported new derivatives HCS12(X) family (KG256,KL128,KC128,KG64,KC64,KL64,HZ256,HZ128,HZ64,HN64,XFR128,XFR64)
	- Additional pin settings (pull-up, open drain, reduced drive) was added to Peripheral Init components
	- Corrections in AsynchroSerial, AsynchroMaster and AsynchroSlave components: Method RecvBlock modified - the method now returns all available data (up to requested amount) in the receive buffer even when a reception error is detected. The previous version in this case stopped immediately and returned with incorrect number of data received.
	- AsynchroSerial: Problem with the OnFullRxBuf event not called when the RTS enabled fixed.
	- Capture: GetStatus method added for getting capture status in polling mode.
	- Init_FLASH_HCS12.drv: Protection register initialization has been added for HCS12X derivatives.
	- IntEEPROM: Fixed bug in internal programming methods for not correctly re-enabled interrupts in code for HCS12X derivatives.
	- HCS12 CPU components: Property re-aranged, Clock monitor settings added.
        - HCS12 CPU components: PLL multiplication factor and Reference divider can be set manually.
        - HCS12 CPU components: Interrupt vector table address seting moved from 'Build option tab' to the 'Properties\Internal resource mapping'.
        - HCS12 CPU components: Generation of the linker command file improved - Realocation, Align, Fill pattern, Code overlapping, Const data overlapping properties added.
        - HCS12 CPU components: Placement part of PRM file can be naw changed by the user.
        - HCS12 CPU components: Separate ISR can be now generated for the interrupts not handled by PE.
	- FreeCntr : Property Reset Counter on compare added
        - Precision timer mode of ECT device supported in high level timer components
	- Init_PMF component: Properties: Stop in wait mode, Stop in freeze mode, Pair X Aligned items have redesigned in the component. Group PWM generator ABC has been removed and its functionality is now implemented in group PWM generator A, which is common for muliple and single generator mode. Property Swap Pair X has been moved into the group Hardware Acceleration and redesigned. Functionality of "PWM X pin" group has been moved to "State of the pin in SW Ctrl" property.
        - Init_TIM, Init_ECT, Init_PWM, Init_PMF, Init_RTI: - settings located in groups ECT,TIM,PWM,RTI,PMF has been redesigned.
        - MC9S12XDT384_144 and MC9S12XDT384_112 are updated according to latest datashhet and are not backward compatible. These MCUs must be reinserted into the project and set by the user again.
        - HCS12 CPU components: Fixed bugs in the memory resource allocation (RAM/EEPROM/FLASH) that can caouse incompatible settings, errors can appear in the 'Properties' and 'Build option tab' if the projct created in the previous version is opened. You can use 'Set default memory segments' button  in the 'Build option tab' to set default memory allocation or edit settings manually.
	- HCS12 CPU components: Frequency range checking of input clock and internal bus frequency has been enhanced. Please note that some CPU derivatives have speed options (e.g. 9S12Q128CFA16 vs 9S12Q128CFA8) - see property 'CPU type' in the CPU component.

PE-Plugin 3.82
--------------
	- In Memory map window: highlighting the selected memory block from inspector item
	- Inspector - Integer items - it is possible to switch between number radix DEC/HEX also for read-only items
	- HTML page with all supported "tip of the day" is generated into  subdirectory DOCs\
	- ISRs from components are displayed in the project tree
	- New option "Environment Option - Environment - User Interface" for switching PE-UI to MCU initialization mode
	- Project configuration contains user comment (see inspector). User comments are displayed in the hint in the project tree for configurations and components
	- New project option "Delete unused events" supported
	- New option "Use default PDF viewer" added into Environment options (allows disable PE PDF Search)
	- Supported customization of CPU package colors (see Environment Options - Environment - Customize colors)
	- Fixed problem with command line parameters in plugin (Issue #2474)
	- New environment option: Hint Pause
	- Acrobar Reader 7.0 supported, Peripheral PDF search no more supported (available full text search including regular expressions)
	- New environment option allows to disable background picture of the CPU package
	- 'Go to Processor Expert Home Page' menu command always available.
	- Fixed Ctr+C, Ctrl+V, Del and other keys issue in PE windows in CodeWarrior.
	- CW plug-in will not longer ask FlexLM for licenses without family extension (FEATURE ProcessorExpert and PE_xxx). This will prevent UNSUPPORTED records in FlexLM floating license server log.
	- New feature allows to disable generation of non-component modules - from popup menu of the module displayed in PE project tree
	- New filter in Peripheral Usage window: Show Used Peripherals Only
	- Unused peripherals on CPU package are displayed as grayed
	- Removed "CPU types overview" window (and View / CPU types overview command)
	- Removed Bean Keywords tab from Bean Selector

Bean Wizard:
------------
	- GUI: Add property dialog - added icons for basic properties.
	- Bean's category dialog - alphabetically sorted categories
	- Fixed default focus of open component dialog.
	- Faster start of the "Open component" dialog
	- Template open dialog - added visual information for read-only templates
	- Customizable highlight of the methods' beginning in the Beanwizard editor.
	- BeanWizard's editor: line numbers can be shown for every line. For more details see Options dialog, page Editor
	- Added note of the component category in the "General page" of html documentation
	- Fixed: Launching help documentation for component opened as "read only"
	- Added sorting list of properties in Page Help, subpage Properties (using popup menu)
	- GUI change: visual changes in the Drivers page. Some buttons have been replaced by tree view.
	- fixed exception during editing interfaces: caused right button clicking on the empty listbox with registered templates
	- Fixed adding event into the interface from the inherited component.
	- Added toolbar with basic properties to simply add them into the component.
	- Fixed copying properties into closed groups (using drag'&'drop).
	- If the component on disk is changed and opened in the "Bean Viewer", user is asked for reloading the component.
	- View Bean window - properties that cannot be dragged are drawn by darker color
	- Internal editor: new short-cuts Ctrl+K Ctrl+G and Ctrl+K Ctrl+H  for commenting/uncommenting selected block of text with one-line comment //

PE 2.96
-------
	- Supported new derivatives HCS12X family (XDP512,XDT512,XDT384,XDT256,XD256,XDG128,XD128,XD64)
	- Supported new derivatives HCS12 family (Q128,Q96,Q64,Q32)
	- Bean ExternalI2C was renamed to SW_I2C
	- Deprecated components ADConverter and ADfast are no more supported, component ADC covers all functionality
	- PESL (Processor Expert System Libory low level macros) no more supported
	- In Memory map window: highlighting the selected memory block from inspector item
	- Inspector - Integer items - it is possible to switch between number radix DEC/HEX also for read-only items
	- HTML page with all supported "tip of the day" is generated into  subdirectory DOCs\
	- ISRs from components are displayed in the project tree
	- Project configuration contains user comment (see inspector). User comments are displayed in the hint in the project tree for configurations and components
	- New project option "Delete unused events" supported
	- New option "Use default PDF viewer" added into Environment options (allows disable PE PDF Search)
	- Supported customization of CPU package colors (see Environment Options - Environment - Customize colors)
	- Fixed problem with command line parameters in plugin (Issue #2474)
	- New environment option: Hint Pause
	- Acrobar reader 7 supported, Peripheral PDF search no more supported (available full text search including regular expressions)
	- New environment option allows to disable background picture of the CPU package
	- 'Go to Processor Expert Home Page' menu command always available.
	- Fixed Ctr+C, Ctrl+V, Del and other keys issue in PE windows in CodeWarrior.
	- CW plug-in will not longer ask FlexLM for licenses without family extension (FEATURE ProcessorExpert and PE_xxx). This will prevent UNSUPPORTED records in FlexLM floating license server log.
	- New feature allows to disable generation of non-component modules - from popup menu of the module displayed in PE project tree
	- New filter in Peripheral Usage window: Show Used Peripherals Only
	- Unused peripherals on CPU package are displayed as grayed
	- Chanel configuration in the components Init_ADC and Init_PWM have been replaced by dynamic channel list. The new versions of these init components are not backward compatible.

Bean Wizard:
------------
        - Supported Bean Wizard version 1.19
	- Added note of the component category in the "General page" of html documentation
	- Added sorting list of properties in Page Help, subpage Properties (using popup menu)
	- Added toolbar with basic properties to simply add them into the component.
	- Bean's category dialog - alphabetically sorted categories
	- BeanWizard's editor: line numbers can be shown for every line. For more details see Options dialog, page Editor
	- Customizable highlight of the methods' beginning in the Beanwizard editor.
	- Faster start of the "Open component" dialog
	- Fixed adding event into the interface from the inherited component.
	- Fixed copying properties into closed groups (using drag'&'drop).
	- Fixed default focus of open component dialog.
	- Fixed exception during editing interfaces: caused right button clicking on the empty listbox with registered templates
	- Fixed importing ANSI C module into the component (problems with modulo operator % and macroprocessor's % - % is converted into %%
	- Fixed: Launching help documentation for component opened as "read only"
	- GUI change: visual changes in the Drivers page. Some buttons have been replaced by tree view.
	- GUI: Add property dialog - added icons for basic properties.
	- If the component on disk is changed and opened in the "Bean Viewer", user is asked for reloading the component.
	- Internal editor: new short-cuts Ctrl+K Ctrl+G and Ctrl+K Ctrl+H  for commenting/uncommenting selected block of text with one-line comment //
	- Template open dialog - added visual information for read-only templates
	- View Bean window - properties that cannot be dragged are drawn by darker color.


PE 2.95
-------
        - Supported new derivatives of the HCS12 family (GC16, GC32, GC64, GC128, E32, E256, H256)
        - XML project settings documentation is generated automatically during code generation
        - New Processor Expert menu group Options has been added. It includes Environment, Project and Application Options for Processor Expert. It replaces Options used as a dummy PE pre-linker in Preference panels. Application, Project and Environment are controlled in new common dialog window by inspector items.
        - Names of interrupt vector handlers can be duplicated for different interrupt vectors (only warning is displayed), e.g. interrupt vector handler may be shared for different interrupt vectors.
        - Support of 16K flash HCS12 CPU has been added to the memory map.
        - External modules and libraries, that are linked to the application, are listed in the project tree.
        - The 'Track/review changes' option allows to control adding/removing access paths.
        - The 'Target CPU Structure' window has been renamed to 'Target CPU Timing Model' window.
        - Added new menu command: Help | Processor Expert On-line Support.
        - The Tip-of-Day has been added to About dialog.
        - The Tip-of-day is supported by start-up dialog.
        - Fixed bug with resetting Target Output directory by the PE plug-in.
        - The Undo for code design option has been renamed to Enable Undo/Redo in the PE Environment Options.
        - Generating of an ISR into CPU event module is supported (on the PE Project Options).
        - FreescaleEthernetAPI component updated.
        - Some bugs have been fixed.
        - CodeWarrior HCS12 Compiler, version 5.0.24 and higher is required.
        - The 'Save Desktop' command has been added into Processor Expert | Options menu.
        - The 'Set memory areas default' property has been added into Build Options of the CPU Bean Inspector.
        - The interrupt vector memory area INT_VECTORS has been added to HCS12 derivatives.
        - The FLASH and EEPROM non-volatile registers' memory areas have been reserved and cannot be overlapped by a memory area.
        - The basic support of the Freescale Serial Monitor has been added into HCS12 CPU components.
        - The external bus support (Operating mode of the MCU) has been improved.
        - The HCS12 CPU components' properties have been rearranged.
        - The Motorola trademarks has been replaced by Freescale.

Bean Wizard:
------------
        - Supported Bean Wizard version 1.18
        - Online preview of the edited hint in an html form. (BeanWizard's page Help).
        - Page help of BW supports converting selected text into the html links and lists using popup menu.
        - Ability to restore the state of the "group-based" properties has been added into the state when the component is loaded.
        - The hierarchical tree for selecting of a component has been added in the dialog Open component.
        - New option for showing modified lines after last save/load has been added in the internal editor.
        - Beans, that are opened as read only (except protected components where user has no right to edit them), can display drivers in read only mode.
        - Method's/Event's include files (*.inc) are edited with highlight.
        - Added code snippets for editing drivers in the editor. Use short-cut "Ctrl+J".
        - Fixed creating inherited overridden method's body for methods with more parameters in the Bean Creator.
        - New functionality to expand/collapse all nested group properties has been added.
        - Editor filters the list of macros in the "inside code" window as the user types (hides macros that do not fits to the typed chars)

PE 2.94
--------
        - Updated for CodeWarrior 3.1 compiler.
        - Some bugs have been fixed.

PE 2.93
--------
        - Supported new derivatives of the HCS12 family (B128, B64, C64, C96, C128, NE64, KG128, KT256, KT128, UF32)
        - Configuration inspector added. It allows using optimization settings.
        - CMD files are not removed from project if generating of this file is disabled.
        - Processor Expert Environment disabled when PE is working.
        - Files opened in IDE editor are closed when they are removed by PE.
        - Supported Bean Wizard 1.17
        - The __RESET_WATCHDOG macro has been added into IO maps of all derivatives.
        - The Bean Wizard help and Bean Wizard ANSI-C import was updated.
        - New command 'Freeze Generated Code' supported - under 'main menu - Code Design'.
        - Bean Selector - added list of all supported component in alphabet order (including fast-search)
        - Help 'Bean Keywords' item has been added in Help | PE menu
        - Support of automated updates of PE_Plugin.dll from UPDATE directory has been added.
        - Support of <CodeWarrior>\ProcessorExpert path.
        - Fixed bug with build non-PE projects
        - Fixed bug in timing calculation for component that uses RTIshared component and requests to set 0% error
        - 'Code Design' menu item changed to 'Code Generation'
        - Generated files paths stored relatively in mcp file.
        - IDE disabled, when PE working.
        - Changes in creating component template - customizing of component items is optional, component template dialog is opened first. Corresponding command renamed.
        - Added support of Back/Forward buttons in Bean Inspector
        - Put invocation into editor menu removed
        - New command "Copy Project To" in pop-up menu of Project panel
        - The SynchroMaster and the SynchroSlave components' license have been changed to Basic components.

PE 2.92
--------
        - Supported new derivatives of HCS12.

PE 2.91
--------
        - Supported Bean Wizard 1.16
        - Supported new HCS12 derivatives

PE 2.90
--------
        - OSEK support has been added.

PE 2.89
--------
        - Menu item 'Put invocation into editor' added into Project panel local menu
        - 'Help' menu items added into Project panel local menu
        - Bean Wizard menu item is shown only when BW_plugin.dll can be found.
        - OLE drag'n'drop of method supported
        - New startup is supported


PE 2.88
--------
        - Supported families HCS12
        - Drag and drop of method invocation from Project panel supported

PE 2.87
--------
        - Supported Bean Wizard 1.12
        - Supported new HCS12 derivatives
        - Supported XTAL 32.768kHz on GP32 derivative
        - Supported QT2/QY2 derivatives
        - Minor bug fixed
        - Stand-alone version of PE is not included

PE 2.86
--------
        - Licensing for components added
        - More CPUs included

PE 2.84
--------
        - User templates included in the Bean selector.
        - Quick Start added into documentation

PE 2.83
--------
        - Processor Expert demo project contains .mcp projects
        - PESL library support for CW added
        - Minor updates in the drivers
        - Checking of target linker added

PE 2.82
--------
        - Environment options and Project options panels added into target settings.
        - Documentation for plug-in added

PE 2.81:
--------
        - Support for PE_plugin created
        - This version is based on the previous demo version and PE stand-alone non-commercial releases.


DOCUMENTATION UPDATES
---------------------

Online help is updated against the printout.


I. UNINSTALLATION
=================
Please follow the instruction for uninstalling CodeWarrior. Processor Expert is uninstalled
as part of it.

Note:
Microsoft stands for Microsoft Corporation.

