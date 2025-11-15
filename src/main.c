#include "./die-rolling.c"
#include "./command-line-interface.c"

int main(int argc, char *argv) {
	switch argv[1] {
	case "help":
		printUsage();
	case "roll":
		cliRollDie();
	}
}

void printUsage() {
}
