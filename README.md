# Using Github as a team
## Basic github / git commands
**NOTE:** I (Josh) am no expert at Github/git. I have only recently starting using it whenever I can for university / personal projects. What ill go through here will be basic commands in case I send you guys in the wrong direction. If you are truly interested in how git and source control works. Probably watch a long guide or read the official github website documentation to see exactly what everything does.
<br/><br/>
**NOTE:** if you use Github Desktop, you will have a nice GUI to help you work around commiting, pulling etc. I would say its recommended if you dont want to go and learn something else. Although I would recommend learning git (essentially using github via the command line), as its a very good skill to have in our industry.
### Setting it up on our own end
After youve been given access to this repository, you will need to 'clone' it onto your machine to work on it. This can be done by doing this:
- For Github Desktop:
  - File->Clone Repository
  - Click the tab which specified this repository, you can also type the URL in manually
  - Choose where you want to copy it to
- For git (CLI)
  - In the parent directory that you want the project in, run ```git clone https://github.com/SecondOccurrence/ICT289-Assignment-2/```
 
Both of these will create a directory containing the latest code found in the ```main``` branch

### Working on our own tasks
#### Branches
When beginning work on our task, whatever it may be, we will create a branch of the current ```main branch``` this can be done by doing the following:
- For Github Desktop:
    - Click the current branch tab at the top
    - Click ```New Branch```
    - Type the name of the new branch
    - Select the branch to base it off of, in almost every case it should be ```main```
    - Switching branches can be as simple as clicking the top branch bar and select the branch you want to work on
- For git (CLI)
    - running ```git branch``` will list all your current branches
    - run ```git checkout -b <new branch> <branch to base off>``` to create a new branch based off another branch (in most cases ```main```)
      - This will create a branch based on the most current revision, (most recent version after ```git push/pull```
      - Switching branches can be done through ```git checkout <branch>```. Say, if you want to change from ```main``` to ```feature/pool-table```:
          - ```git checkout feature/pool-table```
#### Committing (adding local changes)
After completing part of a task for example:
- Finished adding up/down/left/right movements for the camera
  - The above is an example of a task big enough for a commit. To commit your work, you can do the following:
- For Github Desktop
  - Under the listed changes on the left, type an appropriate title/description, and press commit
- For git (CLI)
  - add your work ```git add <files>``` or if you just want all ```git add .```
    - If you have a text editor i believe its git bash (preinstalled with git on windows) or vi (linux) or set your own text editor using ```git config```
  - commit your work ```git commit -a -m <commit message>```

**VERY IMPORTANT**: Keep your commits small and precise. Be sure you changing one thing one at a time. The reason its a good idea to do so is so we have an accurate backlog of changes made. In the case that we need to go back to when the project works, we know exactly how far back we need to go. It can be quite annoying going back and seeing a monolith commit containing changes that you have done over the past two days.
#### Pulling (retrieving work from others)
If you're working on a task with someone else, chances are they've done work on it before you, and you need to sync your project with what they've committed.<br/><br/>
**IMPORTANT** committing your own work before pulling when working with others causes issues when calling ```git push``` as there are changes you done have that exist on the current branch youre committing to. Be sure to always pull first if youre coding in tandem with another.<br/><br/>
**IMPORTANT** It should also be noted that we should design our set tasks so that our work is independent of others work, but all coming together to progress through the assignment.
  
## Understanding .gitignore
If you aren't familiar with git or github, ```.gitignore``` is a file containing a list of file/directory names to be excluded from adding to the repository. Currently, whats added if you look into the file is ```build/```. This will exclude anything in the build file from being included in the repository. If you generate any custom files of your own. e.g. .vscode files from a vscode project, please include ```.vscode/``` in the ```.gitignore``` file as those configuration files are specific to your machine, not ours.

# Generating the Code::Blocks file
- This assignment restricts the submission to a Code::Blocks project. CMake can generate a Code::Blocks project for us that works with the current project directory.
- Command to run at the project's root directory, you need to use CMake on the command line. Open a command line in the project's ```build``` directory. Then type the following command:
    - For Windows:
      - ```cmake -G "CodeBlocks - MinGW Makefiles .``` 
      - This command generates required CodeBlocks project files in the current directory (we want to be in the ```build directory```
      - Be sure to include the ```.``` at the end. It isnt a full stop. Its to indicate that we want the files to be built in the current directory.
      - **NOTE** I have ran this a few weeks ago. It would not run off the bat. I can't remember exactly what I did to fix it. I think it was changing the build target from the currently selected option to another of the 3 options present. It was found i think at ```build->select target``` I will look into this. So long as we configure the project correctly before submission, it will not be an issue on the marker's end.
    - For Linux / Apple:
      - ```cmake -G "CodeBlocks - Unix Makefiles .```
      - Same as above command, but for Unix
- **NOTE:** We will be generating a Windows Code::Blocks project for submission.

# Program file formatting
## Commenting
- Every file should have a comment block at the top of it. It should follow this format:
```comment
/*
 * FILE: ___ ??  TBA
 * PURPOSE: ____
 * DATE: ___
 *
 * VERSION HISTORY:
 * - v1.0 (date): short comment
 *   Contributed by name, student number
 * - v1.1 (Date): short comment
 *   Contributed by name, student number
 *
 */

```
- Keep the version numbers simple, just increment by 0.1 each change
    - Although, be sure the changes are significant enough and within reason, dont want a 200 line comment block at the start
    - This is just to keep track of changes on a low level. We could check through github but I assume we are no masters at this. Better to have history like this so everyone can easily understand whats been going on
    - Could introduce something like ```v1.1.1``` for incomplete work ?, then merge to ```v1.2``` when you have completed the main task
  ## Program Design
  Of course, write code your own way. However, when finalising code, be sure to refactor it (clean up). Go through, remove unused variables, change logic flow for easy to read code. A good video that goes through writing "clean" code is attached [Here](https://www.youtube.com/watch?v=CFRhGnuXG-4).
  - **NOTE** The video has extremely strict rules. For the code we write for a game engine, I would say rather prefer efficiency over clean code. Just take the video into account.

# Understanding CMake
CMake is used to allow for cross-platform cross-IDE/editor work with teams/by yourself. You can write a program on one operating system or text editor and compile / build project files for another operating system / IDE. I (Josh) don't use Code::Blocks for this unit, and would rather stay away from it. Im sure you guys would prefer something like VSCode etc. rather than Code::Blocks as well. With CMake, we can code and build on our own text editors / IDEs, whilst also ensuring we submit a working Code::Blocks project as required for submission.

As another example, we can have team members who don't use the Windows OS work on the same project files as Windows users, without having the need to import their own OS specific libraries. CMake handles this for us.
## CMake use for the individual
### How do use
- If you use a base text editor, Notepad++, vim, neovim etc:
    - Edit the files as you would normally, no need to create a custom project
- If you use Visual Studio Code:
    - Above applies, no need to make a fancy project file with .vscode folder. If you do, be sure to add it to the ```.gitignore``` file. Open the folder and edit it as you would
- If you use Visual Studio
    - There is an import project through CMake button which is provided by default in Visual Studio. Import the project this way and this Visual Studio should import it for you. If this creates any extra config folders, be sure to add the generated folders/files to the ```.gitignore``` folder
- If you use Code::Blocks
    - To create a codeblocks project, see [Generating The Code::Blocks file](#generating-the-codeblocks-file) found at the top
### Compiling and running the program
If you're not using something like Code::Blocks, or Visual Studio, you need to call cmake to run the program via the command line. This is very simple. First be sure to download CMake
**NOTE:** the minimum version to download is specified in each ```CMakeLists.txt``` file. ```v3.29```. Anything above should work fine.
- To run, you first need to build the project:
  - ```cmake --build build```
    - tell cmake to ```--build```. The destination for all build files is ```build```
    - **NOTE**: the above command assumes you are in the root directory of the project
  - After building the project, you need to call the executable to run it. In the CMakeLists.txt file, we've specified that the name should be ```output```
    - ```./build/output``` executes the program, assuming you are in the projects root directory<br/>
    
Instead of calling two of these commands, you can create an executable file which performs both of them for you
- For Windows
  - Create a batch (.bat) that executes both commands. An example could be like this
```comment
@echo off
cd /d <full_path_to_project_root_directory>
cmake --build build
.\build\output
```
- For Linux and Apple
  - Create a shell (.sh) or bash script that executes both commands. An example could be like this
```comment
#!/bin/sh
cmake --build build
./build/output
```
  - Be sure this file has execution privileges

- The windows example could be done in any directory. The linux and apple example assumes you are in the projects root directory.
  - **IMPORTANT** If this file is located inside the assignment project on your machine, be sure to include it in the ```.gitignore``` file.
## Understanding CMakeLists.txt
- Each subdirectory will contain its own ```CMakeLists.txt``` file. This is to maintain a clean project and modularity. This also helps the ```CMakeLists.txt``` file become less cluttered
  - EXAMPLE: ```src/math/CMakeLists.txt```
```comment
cmake_minimum_required(VERSION 3.29)

set(SOURCES
    matrix_operations.c
    vector_operations.c
)

set(HEADERS
    matrix_operations.h
    vector_operations.h
    geometry.h
)

target_sources(output PRIVATE ${SOURCES} ${HEADERS})
```
  - For every ```*.c``` file in the directory, write into the ```SOURCES```
  - For every ```*.h``` file in the directory, write into the ```HEADERS```

- Note that, for every new directory created, you must also add that directory into the ```src/CMakeLists.txt``` file as follows:
```comment
IN src/CMakeLists.txt

...
add_subdirectory(test)


END
```
- where ```test``` is the name of the directory

## Understanding the root CMakeLists.txt
- Whilst this file shouldnt be our concern going forward, here is what each line does in the CMakeLists found in the root directory:
- ```cmake_minimum_required(VERSION 3.29)``` - define the minimum version of CMake to use
- ```project(output DESCRIPTION "ICT289 Assignment 2" LANGUAGES C)``` - create a project ```output```, state its description and define the language used, ```C```
- ```add_executable(output)``` - create the exectuable, named ```output```
- ```set_target_properties(output PROPERTIES WORKING_DIRECTORY ${CMAKE_CURRENT_COURSE_DIR}/)``` - be sure the working directory of the program is at the root directory. this is to be sure paths when, say loading an off file from ```public/3D-data``` is an accurate path
- ```target_compile_options(...)``` - sets compiler options. Here were adding all warnings when compiling. This is to show any incorrect syntax, unused variables etc.
- ```add_subdirectory(lib)``` - calls ```CMakeLists.txt``` found in the ```lib/``` directory
