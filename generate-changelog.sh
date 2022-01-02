#!/bin/sh
git --git-dir=./.git --work-tree=. log --stat -M -C --name-status --no-color --no-decorate | fmt --split-only > ChangeLog
