# First Task Note

## LINUX

### Mission 0:
**Making multiple directories in one line one inside the other**  
`mkdir -p folder_name/folder_inside_name`

---

### Mission 1:
**To download files from a link**  
`wget link`

**To search for how many times a word was mentioned in a certain file**  
`grep -o word file_name | wc -l`

**To save results of compiling in a certain file**  
`grep -o word file_name | wc -l > path/to/destination.txt`

**To find the line with a certain phrase and its line number**  
`grep -n "phrase you're searching" file_name > output.txt`


---

### Mission 2:
**What is stdin, stdout, stderr?**

1. **stdin** redirects (saves) input to a file  
   **Command:** `0> file_name`
2. **stdout** redirects (saves) output to a file  
   **Command:** `1> file_name`
3. **stderr** redirects (saves) errors to a file  
   **Command:** `2> file_name`

---

### Mission 3:
**To find the line with a certain phrase and its line number**  
`grep -n "phrase you're searching" file_name > output.txt`

### Extra Notes 
**To move files from a directory to another**
`mv folder1 folder2 file1 destination_directory/`

**Delete a directory and its contents recursively:**  
`rm -r directory_name` 
`rm filename`

**To run a code and save results in a file**
gcc all_in_one.c -o main

**cannot pull with rebase: You have unstaged changes solution**
just stash your unstaged changes `git add` pull then return them and push
`git stash`
`git pull --rebase`
`git stash pop`
