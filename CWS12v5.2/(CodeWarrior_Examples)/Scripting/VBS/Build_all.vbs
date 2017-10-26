'*********************************************************
' Language       : vbscipt 
' Version        : 1.0
' Shell executed : wscript.exe
' 
' What is done
'   This script is used to build recursively all CodeWarrior (*.mcp)
'   projects found in a given directory tree.
'   The registered version of CW IDE is used for this script.
'   If you have multiple versions of CW IDE installed,
'   launch the 'regservers.bat' file in the 'bin' folder
'   of the IDE you want to use.
'   The script asks for the root folder to scan.
'   In each (sub)folder the script checks if there is 
'   a mcp file 
'     all examples are ignored   
'     and  .old.mcp files are ignored 
'   When an mcp file is found, it opens it in the IDE 
'   and all targets are built.
'   The results of build execution are written in a 
'   report file.
'
' ************************************
' ********  BEGIN  SCRIPT  ***********
' ************************************
 

Option Explicit
 
' Constants 
' Extension of project file
const cMCPext = "mcp"
' Projects to avoid 
const cAvoidProjectAllExamples = "all examples"
const cAvoidProjectAllStationnaries =  "all stationeries"
 

' Global variables
dim fso,cwApp,shell
dim number_Of_Build
dim number_Of_BuildErr
dim folder_to_scan 
dim HaswrittenHeader
 
' Pointer on the COM used
set fso   = CreateObject("Scripting.FileSystemObject")
set cwApp = CreateObject("CodeWarrior.CodeWarriorApp")
set shell = CreateObject("Shell.Application")
  
' Don't interrupt the build process, take default actions for modal dialogs
cwApp.AllowUserInteraction = FALSE
' Call main routine
Main    
 

' **********************************
' ********  END  SCRIPT  ***********
' **********************************
 
'**********************************************************
' 
Sub Main ()
 

' Init 
  number_Of_Build = 0 
  number_Of_BuildErr = 0 
  HaswrittenHeader = FALSE
 
' Delete the log file 
  If (fso.FileExists(GetTextDocumentPath (cwApp))) then  
    fso.DeleteFile(GetTextDocumentPath (cwApp))
  end if  
 
  
' Scan the folder and go 
' Example folderlist ("C:\CodeWarrior\Examples")
 
'If you want to open a Windows explorer first:
'shell.open (dirWin() & "\explorer.exe" )
folder_to_scan = InputBox("Please specify the full path to scan for CodeWarrior project files:", "Folder to scan and build projects ") 
folderlist (folder_to_scan )
 

msgbox "Script ending with " & vbcrlf & cstr(number_Of_Build ) & " builds " & vbCrlf & cstr(number_Of_BuildErr ) & " builds in Error" 
 

end sub 
 
'**********************************************************
' PROC  : Build 
' Input : projpath ==> path of the folder to scan 
'       : cwApp    ==> object CodeWarrior.CodeWarriorApp
' Output: nothing
'**********************************************************
Sub Build (projpath, cwApp)
  Dim  cwProj, cwTrg
  Dim trgCollection, trgName
  Dim txtDoc, txtEngine
  Dim buildMsgs
  Dim i
  
  ' Open the Project
  OpenProject cwApp,projpath, cwProj
  
  ' Create TextDocument
  GetTextDocument cwApp, txtDoc
 
  ' Get TextEngine for Document
  Set txtEngine = txtDoc.TextEngine
  
  'LogProjectMessages txtEngine, projpath & " " & trgName
 
  PrintBeginOfbuild txtEngine, HaswrittenHeader
  
  ' Get the target collection
  Set trgCollection = cwProj.Targets
  
  ' For every target, build, log error messages
  For i = 0 to trgCollection.Count - 1
    Set cwTrg = trgCollection.Item(i)
    trgName = cwTrg.Name
    cwProj.SetCurrentTarget(trgName)
    Set buildMsgs = cwProj.BuildandWaitToComplete
    LogMessages buildMsgs, txtEngine, projpath & " " & trgName
  Next
  
' Save the text document
  txtDoc.Save
' Close the project
  cwProj.Close
End Sub
 

'**********************************************************
' PROC  : PrintBeginOfbuild
' Input : cwTxtEngine ==> TextEngine
'       : status      ==> build status
' Output: nothing
'**********************************************************
Sub PrintBeginOfbuild(cwTxtEngine,status)
  Dim curTime
  if status = FALSE then 
    cwTxtEngine.InsertText("*******************************************************" + vbcrlf)
    cwTxtEngine.InsertText("Build report for : " + folder_to_scan + vbcrlf)
    cwTxtEngine.InsertText("Date : " + CStr(Now) + vbcrlf )
    cwTxtEngine.InsertText("*******************************************************" + vbcrlf)
    status = TRUE
  end if 
End Sub 

'**********************************************************
' PROC  : LogMessages
' Input : cwBuildMsg  ==> Messages
'       : cwTxtEngine ==> object CodeWarrior.CodeWarriorApp
'       : trgName     ==> texts
' Output: nothing
'**********************************************************
Sub LogMessages(cwBuildMsg, cwTxtEngine, trgName)
  Dim errCollection, warningCollection, informationCollection
  Dim errMsg, errCnt, warnMsg, warnCnt, infoMsg, infoCnt
  Dim j,l
  Dim a,b
 
  Set errCollection = cwBuildMsg.Errors
  errCnt = errCollection.Count
  For j = 0 to errCnt - 1
    Set errMsg = errCollection.Item(j)
    cwTxtEngine.InsertText("Error : " + errMsg.MessageText + Chr(13) + Chr(10))
  Next
  
  Set warningCollection = cwBuildMsg.Warnings
  warnCnt = warningCollection.Count
  For a = 0 to warnCnt - 1
    Set warnMsg = warningCollection.Item(a)
    cwTxtEngine.InsertText("Warning : " + warnMsg.MessageText + Chr(13) + Chr(10))
  Next
 
  Set informationCollection = cwBuildMsg.Informations
  infoCnt = informationCollection.Count
  For b = 0 to infoCnt - 1
    Set infoMsg = informationCollection.Item(b)
    cwTxtEngine.InsertText("Information : " + infoMsg.MessageText + Chr(13) + Chr(10))
  Next
  
  If errCnt = 0 Then
    l = len (folder_to_scan) + 1
    cwTxtEngine.InsertText("ok for " + mid(trgName,l) + " " + Chr(13) + Chr(10))
  else 
    l = len (folder_to_scan) + 1
    cwTxtEngine.InsertText("FAILED for " + mid(trgName,l) + " " + Chr(13) + Chr(10))
    number_Of_BuildErr = number_Of_BuildErr + 1
  End If  
  number_Of_Build = number_Of_Build + 1
 
  'cwTxtEngine.InsertText("Date : " + CStr(Now) + Chr(13) + Chr(10) )
End Sub
  
 
'**********************************************************
' PROC  : OpenProject
' Description : open a project in CwApp described by projpath
' Input : cwApp    ==> object CodeWarrior.CodeWarriorApp
'       : projpath ==> path of the folder to scan 
' Output: outProj  ==> project opened
'**********************************************************
Sub OpenProject(cwApp,projpath, outProj)
  Dim cnt,  proj 
    ' Prompt User for project to build and file to save build info
  ' str = InputBox("Enter the full path of the project to build:") 
  
' Open a project
' 1st Param is the path to the Project
' 2nd Param is TRUE if the Project should be open visible, FALSE for invisible
' 3rd Param Project Conversion option. 0 is Yes, 1 is No, 2 is Prompt User
' 4th Param is Revert Panel Option, 0 do not allow, 1 is allow reverting panels
 
    Set outProj = cwApp.OpenProject(projpath, TRUE, 0, 1)
End sub
 
'**********************************************************
' PROC  : GetTextDocument
' Description : Create a text document to save information 
'           about the build
' Input : inApp    ==> Codewarrior Application
' Output: outxtdoc ==> document out 
'**********************************************************
Sub GetTextDocument(inApp, outTxtDoc)
 
' 1st Param is a full path, 2nd Param informs CW that the file should be created
  Set outTxtDoc = inApp.OpenTextDocument(GetTextDocumentPath (cwApp), TRUE)
End Sub
 

function GetTextDocumentPath(inApp)
  Dim projPath, txtDocPath,pos
  projpath = inApp.FullName
  pos = InstrRev(projPath, "\", -1)
  txtDocPath = Left(projPath, pos)
  txtDocPath = txtDocPath & "Build_Report.txt"
  GetTextDocumentPath = txtDocPath
end function 
 
 
 
'**************************************************************************
' PROC  : scan_and_build
' Description : build projects in the folder
' Input : f     ==> folder
' Output: nothing 
'**************************************************************************
sub scan_and_build (f)
  dim fc, f1, ext
  set fc = f.Files
  for each f1 in fc 
    ext = fso.GetExtensionName(f1.path)
    ext = lcase(ext)
    if ( ext = cMCPext) then 
      if (isProjectOk(f1.path)) then 
        Build f1.path,cwApp
      end if 
    end if 
  next 
end sub
 
'**************************************************************************
' PROC  :folderlist
' Description : care about folders & subfolders - this proc is recursive
' Input : folderspec  ==> path of the folder
' Output: nothing 
'**************************************************************************
 
sub folderlist (folderspec)
  dim f, f1, sf
 
  if ( folderspec <> "" ) then 
    set f = fso.GetFolder(folderspec)
    scan_and_build(f)
    
    set sf = f.SubFolders
    for each f1 in sf  
      folderlist(f1.path)
    next
  end if 
end sub 
 
'**************************************************************************
' FUNCTION  :isProjectOk
' Description : returns if the project has to be build
' Input : chaine ==> path of the project
' Return: TRUE or FALSE
'**************************************************************************
Function isProjectOk(chaine)
  dim nb,s
  nb  = instr(1,chaine,".old")
  if nb = 0 then 
    nb  = instr(1,chaine,cAvoidProjectAllExamples)
  end if 
  if nb = 0 then 
    nb  = instr(1,chaine,cAvoidProjectAllStationnaries)
  end if 
  if (nb = 0 ) then 
    isProjectOk  = TRUE  
  else 
    isProjectOk  = FALSE
  end if   
  
end function 
 
'**************************************************************************
' FUNCTION  :dirWin
' Description : returns the path of windows
' Input : none
' Return: string of path of the windows folder
'**************************************************************************
Function dirWin()
  dim p
  p = fso.GetSpecialFolder(0)
  dirWin = p 
 
end function
