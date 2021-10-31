previous_hash="";

function get_file_contents {
    if [ -z "$1" ]
    then
        str="";
    fi

    for file in $(ls -1)
    do
        if [[ $file =~ .*\.(c|h)$ ]]
        then
            str="${str}$(cat $file)";
        fi

        if [ -d $file ]
        then
            cd $file;
            get_file_contents next;
        fi
    done

    if [ ! -z "$1" ]
    then
        cd ..;
    fi

    if [ -z "$1" ]
    then
        echo $str;
    fi
}

while :
do
    sleep 1;
    current_hash=$(get_file_contents | sha512sum);
    
    if [ "$previous_hash" != "$current_hash" ]
    then
        bash compile.sh
        previous_hash=$current_hash;
        echo "Compiled!";
    fi
done


