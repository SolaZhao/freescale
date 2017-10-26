%-Address in CPU address space
%;**%>12Address in CPU address space
%;**%>17Address%>40: %#h%ADDR
%;**%>17Address is external%>40: %ADDR_External
%;**%>17Address is internal%>40: %ADDR_Internal
%;**%>17Address is in RAM%>40: %ADDR_RAM
%;**%>17Address is in ROM%>40: %ADDR_ROM
%;**%>17Address is in FLASH%>40: %ADDR_FLASH
%;**%>17Address is in EEPROM%>40: %ADDR_EEPROM
%-
%-Boolean group
%ifndef BOOLGROUP
%;**%>12Boolean group%>40: macro is not defined
%elif BOOLGROUP=''
%;**%>12Boolean group%>40: macro is defined
%else
%;**%>12Boolean group%>40: %BOOLGROUP
%endif
%-
%-Boolean yes/no
%ifndef BOOL
%;**%>12Boolean yes/no%>40: macro is not defined
%elif BOOL=''
%;**%>12Boolean yes/no%>40: macro is defined
%else
%;**%>12Boolean yes/no%>40: %BOOL
%endif
%-
%-Date
%;**%>12Date:
%;**%>17Day%>40: %DATEDay
%;**%>17Month%>40: %DATEMonth
%;**%>17Month long%>40: %DATEMonthLong
%;**%>17Month short%>40: %DATEMonthShort
%;**%>17Year%>40: %DATEYear
%;**%>17Day of week%>40: %DATEDayOfWeek
%;**%>17Day of week long%>40: %DATEDayOfWeekLong
%;**%>17Day of week short%>40: %DATEDayOfWeekShort
%-
%-Directory
%;**%>12Directory:
%;**%>17Input value%>40: "%DIR"
%;**%>17Absolute path\%>40: "%DIR_"
%;**%>17Absolute path%>40: "%DIR__"
%-
%-Enumeration (color)
%;**%>12Enumeration%>40: %ENUM
%-
%-External bitmap file
%;**%>12External bitmap file
%;**%>17Input%>40: %BITMAP
%;**%>17Extension%>40: %BITMAPFileExt
%;**%>17File name%>40: %BITMAPFileName
%;**%>17Absolute file%>40: %BITMAPFilePath
%;**%>17Height%>40: %BITMAPHeight
%;**%>17Width%>40: %BITMAPWidth
%;**%>17Size%>40: %BITMAPSize
%-
%-External file
%;**%>12External file
%;**%>17Input%>40: %FILE
%;**%>17Extension%>40: %FILEFileExt
%;**%>17Name%>40: %FILEFileName
%;**%>17Absolute file%>40: %FILEFilePath
%-
%-Group of items
%;**%>12Group of items%>40: no settings
%-
%-Integer - signed
%;**%>12Integer - signed%>40: %INT
%-
%-Integer - unsigned
%;**%>12integer - unsigned%>40: %WORD
%-
%-List of items
%;**%>12List of items
%;**%>17Number of items%>40: %LISTNumItems
%;**%>17Maximal index%>40: %LISTMaxItem
%for i from [0..%LISTMaxItem]
%;**%>17Real%i%>40: %REAL%i
%endfor
%-
%-String
%;**%>12String%>40: %STRING
%-
%-String list
%;**%>12String list
%;**%>17Number of lines%>40: %STRLISTLines
%-
%-Time
%;**%>12Time
%;**%>17Hour%>40: %TIMEHour
%;**%>17Min%>40: %TIMEMin
%;**%>17Sec%>40: %TIMESec
%-
%-Speed modes
%;**%>12Speed modes
%;**%>17Number of speed modes%>40: %runSpeedModeNum
%ifdef SpeedModeList
%-new version of speed mode support
%for f from SpeedModeList
%;**%>16 %f%>40: %[%for_index_1,runSpeedMode]
%endfor
%else
%;**%>17High speed mode%>40: %runHighSpeed
%;**%>17Low speed mode%>40: %runLowSpeed
%;**%>17Slow speed mode%>40: %runSlowSpeed
%endif
