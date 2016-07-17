/*
 * common.h
 *
 *  Created on: Jul 15, 2016
 *      Author: cesare
 */

#ifndef COMMON_H_
#define COMMON_H_



#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <random>

#ifdef _WIN32
#define NOMINMAX
#include <Windows.h>
#else
# include <sys/time.h>
#endif

#include "cpprest/json.h"
#include "cpprest/http_listener.h"
#include "cpprest/uri.h"
#include "cpprest/asyncrt_utils.h"


#endif /* COMMON_H_ */
