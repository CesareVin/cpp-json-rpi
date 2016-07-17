/*
 * BaseCommand.h
 *
 *  Created on: Jul 15, 2016
 *      Author: cesare
 */

#ifndef BASECOMMAND_H_
#define BASECOMMAND_H_

#include "ICommand.h"

#include<string>
#include<vector>
#include<map>

class BaseCommand: public ICommand {
public:
	BaseCommand(string name,string device,map<string,string> schema);
	BaseCommand();
	virtual ~BaseCommand();
};

#endif /* BASECOMMAND_H_ */
