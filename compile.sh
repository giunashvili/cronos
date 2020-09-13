if [ "$(uname)" == "Darwin" ]; then
    clang ./framework/index.c `mysql_config --cflags` `mysql_config --libs` -o ./public/index.cgi        
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    gcc ./framework/index.c `mysql_config --cflags` `mysql_config --libs` -o ./public/index.cgi
fi