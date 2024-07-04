#define SCRIPTS_HOME	"$HOME/.config/nixja/sysutils/"


//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/							/*Update Interval*/	/*Update Signal*/
	//{"Mem:", 	"free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	30,			0},
	//{"", 		"date '+%b %d (%a) %I:%M%p'",					5,			0},
	{" ", SCRIPTS_HOME "/internet.sh", 5, 4},
	{"", SCRIPTS_HOME "/battery.sh", 5, 3},
	{"", SCRIPTS_HOME "/volume.sh", 0, 10},
	{"", SCRIPTS_HOME "/datetime.sh", 60, 0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " ";
static unsigned int delimLen = 5;
