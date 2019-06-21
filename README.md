# CmdLineParser
A one-header library for parsing command line.

**NOT TESTED WITH UNICODE**

Use the **Combine** function to combine arguments from the *main* function (to pass into *ParseArguments*).
Use the **ParseArguments** function to parse arguments from singleline arguments.
For immediately use just see *test.cpp*

Support argument format:

**{** *-%FLAG% %PAR_1% PAR_2% ... %PAR_N%* **}** - it is parameters with flags.

**{** *free_par1 free_par2 ... free_par_n* **}**  - it is parameters without flag, i named it as free parameters.

**{** *[FREE PARAMETERS] [PARAMETERS WITH FLAGS]* **}** - Full possible argument format.

*An example:* **{** *cmd.exe "/ping 127.0.0.1" -HIDECONSOLE -OUTPUT "C:\output.txt"* **}**

*NOTE:* parser supports parameters with quotes **["]**

*NOTE:* **ParseArguments** throws several error types, see header beginning.
