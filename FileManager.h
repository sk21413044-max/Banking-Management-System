#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Account.h"
#include <vector>
#include <memory>

bool saveAccounts(const vector<unique_ptr<Account>>& accounts);

bool loadAccounts(vector<unique_ptr<Account>>& accounts);

#endif