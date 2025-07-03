# First Task Note

## LINUX

### Mission 0:
**Making multiple directories in one line one inside the other**  
`mkdir -p folder_name/folder_inside_name`


### Mission 1:
**To download files from a link**  
`wget link`

**To search for how many times a word was mentioned in a certain file**  
`grep -o word file_name | wc -l`

**To save results of compiling in a certain file**  
`grep -o word file_name | wc -l > path/to/destination.txt`


### Mission 2:
**What is stdin, stdout, stderr?**

1. **stdin** redirects (saves) input to a file  
   **Command:** `0> file_name`
2. **stdout** redirects (saves) output to a file  
   **Command:** `1> file_name`
3. **stderr** redirects (saves) errors to a file  
   **Command:** `2> file_name`


### Mission 3:
**To find the line with a certain phrase and its line number**  
`grep -n "phrase you're searching" file_name > output.txt`
