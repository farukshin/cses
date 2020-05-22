from="./bootstrap"
cppfile=./$1/$1.cpp

error() {
    echo "Ошибка создания каталога "$1
    exit 1
}

success() {
    echo "create "$1
    exit 0
}

if [ -z $1 ]; then
    echo "Не задан параметр" && exit 1
fi

cp -r $from $1 &&
    mv ./$1/bootstrap.cpp $cppfile &&
    sed -i 's_^\(//https://cses.fi/problemset/task/\)$_\1'$1'_g' $cppfile &&
    success $cppfile || error $1
