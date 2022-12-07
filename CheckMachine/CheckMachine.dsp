# Microsoft Developer Studio Project File - Name="CheckMachine" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=CheckMachine - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "CheckMachine.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CheckMachine.mak" CFG="CheckMachine - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CheckMachine - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "CheckMachine - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CheckMachine - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "CheckMachine - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "CheckMachine - Win32 Release"
# Name "CheckMachine - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\CAdminWin.cpp
# End Source File
# Begin Source File

SOURCE=.\Cargo.cpp
# End Source File
# Begin Source File

SOURCE=.\CargoCheckMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\CargoInLibMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\CargoInLibWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CargoOutLibMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\CargoOutLibWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CargoSearch.cpp
# End Source File
# Begin Source File

SOURCE=.\CButton.cpp
# End Source File
# Begin Source File

SOURCE=.\CData.cpp
# End Source File
# Begin Source File

SOURCE=.\CEdition.cpp
# End Source File
# Begin Source File

SOURCE=.\CheckRecord.cpp
# End Source File
# Begin Source File

SOURCE=.\CheckRecordWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CheckWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CLabel.cpp
# End Source File
# Begin Source File

SOURCE=.\CLogWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CNewCheckWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CorrectRecordWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CRegistWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CSelectButton.cpp
# End Source File
# Begin Source File

SOURCE=.\CStartWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CTable.cpp
# End Source File
# Begin Source File

SOURCE=.\CTool.cpp
# End Source File
# Begin Source File

SOURCE=.\CtrlBase.cpp
# End Source File
# Begin Source File

SOURCE=.\CUser.cpp
# End Source File
# Begin Source File

SOURCE=.\CWindow.cpp
# End Source File
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\CAdminWin.h
# End Source File
# Begin Source File

SOURCE=.\Cargo.h
# End Source File
# Begin Source File

SOURCE=.\CargoCheckMenu.h
# End Source File
# Begin Source File

SOURCE=.\CargoInLibMenu.h
# End Source File
# Begin Source File

SOURCE=.\CargoInLibWin.h
# End Source File
# Begin Source File

SOURCE=.\CargoOutLibMenu.h
# End Source File
# Begin Source File

SOURCE=.\CargoOutLibWin.h
# End Source File
# Begin Source File

SOURCE=.\CargoSearch.h
# End Source File
# Begin Source File

SOURCE=.\CButton.h
# End Source File
# Begin Source File

SOURCE=.\CData.h
# End Source File
# Begin Source File

SOURCE=.\CEdition.h
# End Source File
# Begin Source File

SOURCE=.\CheckRecord.h
# End Source File
# Begin Source File

SOURCE=.\CheckRecordWin.h
# End Source File
# Begin Source File

SOURCE=.\CheckWin.h
# End Source File
# Begin Source File

SOURCE=.\CLabel.h
# End Source File
# Begin Source File

SOURCE=.\CLogWin.h
# End Source File
# Begin Source File

SOURCE=.\CNewCheckWin.h
# End Source File
# Begin Source File

SOURCE=.\CorrectRecordWin.h
# End Source File
# Begin Source File

SOURCE=.\CRegistWin.h
# End Source File
# Begin Source File

SOURCE=.\CSelectButton.h
# End Source File
# Begin Source File

SOURCE=.\CStartWin.h
# End Source File
# Begin Source File

SOURCE=.\CTable.h
# End Source File
# Begin Source File

SOURCE=.\CTool.h
# End Source File
# Begin Source File

SOURCE=.\CtrlBase.h
# End Source File
# Begin Source File

SOURCE=.\CUser.h
# End Source File
# Begin Source File

SOURCE=.\CWindow.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
