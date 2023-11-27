#!/bin/sed -f
\_//HIDE_,\_//\(EDIT\|SHOW\)_ {
  \_//\(EDIT\|SHOW\)_! d
}
\_//\(EDIT\|SHOW\)_ s_\(.*\)//\(EDIT\|SHOW\) \?\(.*\)_\1\3_
