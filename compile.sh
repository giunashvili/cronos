if [ "$(uname)" == "Darwin" ]; then
    clang ./framework/index.c `mysql_config --cflags` `mysql_config --libs` -o ./public/index.cgi        
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    gcc ./framework/index.c `mysql_config --cflags` `mysql_config --libs` -o ./public/index.cgi
elif [ "$(expr substr $(uname -s) 1 10)" == "MINGW32_NT" ]; then
    # Do something under 32 bits Windows NT platform
elif [ "$(expr substr $(uname -s) 1 10)" == "MINGW64_NT" ]; then
    # Do something under 64 bits Windows NT platform
fi

