verysleepy
==========

verysleepy is a version of Sleepy, a C/C++ CPU profiler for Windows systems, that is maintained by Richard Mitton. See http://www.codersnotes.com/sleepy/. This is a fork that I'm using for some experimentation.

jon's build notes
  Had to d/l WxWidgets and build using dirs from verysleepy's building_wxwidgets.txt
  Had to change a -> to a ((*Type)iter).Get() to quell compiler 
  Note release build of verysleepy will not work unless i rebuild WxWidgets in release mode (the release libs aren't compiled as of now)
  Had to do this copyfiles.bat x86 sleepy\obj\Win32\Debug ... but that didn't work so i just copyed debughelpw.dll from the proper folder in sleepy's src to the obj/win32/debug dir by hand