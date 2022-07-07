#pragma once

#include "class_friend.h"

void CShow_one::showInt(std::shared_ptr<CShow> p) { printf("CShow_one(), a=%d\n", p->a_); }