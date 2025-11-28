# Custom Terminal – C Project  

A modular command-line terminal written in C with support for:

✔ File operations  - readfile, writefile, appendfile, copyfile, mergefile, filewords

✔ Directory operations -Create directory, Remove directory, List directory contents, Change directory, Show current directory path, Create file in current directory, Delete file in current directory
  
✔ Text processing  - countwords, reversetext, uppercase, lowercase, copytext

✔ Search utilities  - multi-word search, suffix/prefix search, compare files, compare files, longest/shortest line search


✔ Math calculations  - arithmetic, factorial, median, mode, sort, statistics

✔ System utilities  - date, time, about, clear screen, banner, uptime 

✔ Custom command registration  

---

We have tried replicating a windows terminal with lesser features as OS calls are not used, but the use of colors makes it look better. Nevertheless we have included 50+ commands that are entirely defined by us. The unique thing is the virtual filesystem using .dirinfo, this is where all the directory operations happen. Our program also has error handling.

Instructions to compile and run:
1. Go to the correct directory
2. Ensure that all files are saved
3. Type "mingw32-make" to compile from the makefile
4. type ".\terminal.exe" to run the program
5. Rest of the instructions appear as u run the program

