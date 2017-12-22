//
// Created by raz on 12/22/17.
//

#include "CommandManager.h"
#include "PrintCommand.h"
#include "CommandManager.h"

CommandsManager::CommandsManager() {
    commandsMap["print"] = new PrintCommand();
    // Add more commands...
}

void CommandsManager::executeCommand(string
                                     command, vector<string> args) {
    Command *commandObj = commandsMap[command];
    commandObj->execute(args);
}

CommandsManager::~CommandsManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it !=
                                   commandsMap.end(); it++) {
        delete it->second;
    }
}