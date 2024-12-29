# OceanLife 🌊

A lighthearted shell written in C to manage files and provide some interactive functionality. Let’s dive into it!

## Commands

Tides - File Creation
Command: tides 'FILENAME.ext'
Description: This command creates a file in the current directory with the specified name and extension (e.g., .txt, .md, .log).
Example:

tides myfile.txt
This will create a file named myfile.txt in the current directory.

---

---

### Waves - File Deletion

Command: waves 'FILENAME.ext'
Description: This command deletes the specified file from the current directory. Be careful, it’s gone for good!
Example:

waves oldfile.txt
This will delete the file oldfile.txt from the directory.

---

---

### Inkit - Write to File

Command: inkit 'FILENAME.ext'
Description: This command allows you to append content to an existing file. It will not overwrite anything that’s already in the file.
Features:
You can type anything you wish into the file (space characters included).
Structure the content with Markdown, if you want to!
End your input by hitting an empty line (pressing Enter on a blank line).
Example:

inkit notes.txt
After running the command, the shell will prompt you to enter content for notes.txt. Once you're done, just hit Enter on an empty line, and your content will be saved.

---

---

#### Additional Commands:

Uhoh - Delete All Files (Be Careful!)
Command: uhoh
Description: This is a fun one—cleans up all files on the C drive... but don’t actually use it unless you’re joking. 😉

---

Greet - Friendly Message
Command: greet
Description: A warm greeting from your humble OceanLife shell. A reminder to smile!

---

General Notes:
Each of these commands operates in the current working directory.
The shell continues running until you enter the exit command, which will safely exit the program.
