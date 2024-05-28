# Getting started

You will need to install several programs. These tools are setup for Windows. Equivalent tools exist for Mac or Linux, but you'll have to install your own. 

You can download each tool from its website or using the `winget` tool built into windows. To use winget, run the provided command on the command line. 

| tool        | description                      | website                                         | winget command                             |
| ----------- | -------------------------------- | ----------------------------------------------- | ------------------------------------------ |
| git         | version control                  | https://git-scm.com/download/win                | `winget install Git.Git`                   |
| tortoisegit | git/windows explorer integration | https://tortoisegit.org/download/               | `winget install TortoiseGit.TortoiseGit`   |
| Arduino IDE | arduino programming environment  | https://www.arduino.cc/en/software              | `winget install arduinosa.ide.stable`      |
| marktext    | markdown editor                  | https://www.marktext.cc/                        | `winget install marktext.marktext`         |
| notepad++   | text editor                      | https://notepad-plus-plus.org/                  | `winget install notepad++.notepad++`       |
| tera term   | serial terminal                  | https://teratermproject.github.io/index-en.html | `winget install TeraTermProject.teraterm5` |

## clone the course repository

Go to My Documents. Do not create a new course folder yet. 

Right click -> Git clone

Paste the course URL (https://github.com/usafa-astro-331/astro-331-2024-fall) and click OK. 



## update arduino

In the Arduino IDE:

- tools -> Board... -> Boards Manager

- search for "SAMD"

- look for "Arduino SAMD Boards"

- Install



# before each lab

(This step is not necessary if you just cloned the course repository.)

**This step should be performed before every lab to ensure you're using current material.** 

- Pull latest changes from course repository
  - Right click the course folder (or any location within the course folder). 
  - Git Sync -> Pull
- Install the required arduino libraries for that lab (listed in lab instructions)
  - tools -> manage libraries
  - search
  - install
