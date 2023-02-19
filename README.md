# BReorder
Beyond Bytes Reorder

## 1 Functions

- Reordering bytes in binary file
- Transforming binary file into text file
- Transforming text file into binary file

### 1.2 Category
![category](./pics/category.png)


### 1.3 Operation Flow
```c
inline void run(){
    //phaser

    //deal loop
        //reader
        /*if (!isForced()){
            //checker
        }*/
        //reverser
        //writer
    //deal loop end

};
```
## 2 Usage

| options | long | desc | 
| --- | --- | --- |
| -E | --elementWidth | element width (unsigned int [=0]) |
| -C | --combinationWidth | group width (unsigned int [=0]) |
| -i | --filePath | file path (string) |
| -t | add an output with .txt format | 
| -f | --forced | without checking (unsigned int [=0]) |
| -? | --help | print this message |
### 2.1 Default 
- *brd [fileDir/fileName.suffix]*

default value of parameters:
| Element width | Combination width |
| :---: | :---: |
|1 Bytes | 4 Element |

*ex:*
- *brd ./a.bin*

the effect of this command is just as below:

| input | output |
| :---: | :---: |
| 0x12345678 | 0x87654321 | 

### 2.2 Assign Element width
you can assign n-bytes combination as follows
- *brd -E [n] [fileDir/fileName.suffix]*\
number should be an arabic figures less than the size of input file

### 2.4 Assign Combination width
n-bytes combination as follows
- *brd -C [n]* [fileDir/fileName.suffix]

### 2.3 To text
add an output file with .txt format 
- *brd -t [fileDir/fileName.suffix]*

## 3 Ouput

### 3.1 Binary
*fileDir/fileName_[parameters].suffix*

### 3.2 Text
*fileDir/fileName_[parameters].txt*

### 3.3 parameters
if using command *brd -n 4 -t*\
[parameters] should be 4_t, then the output file should be *fileDir/filename_n4_t.txt*

## 4 Notice
- ...

## 5 Make contribution
- ...
