url_problem="https://cses.fi/problemset/"

all_problems() {
    curl https://cses.fi/problemset/ 2>/dev/null |
        grep -P -o '<a href=\"\/problemset\/task\/(\d*)\">([\w,\s]*)<\/a>' |
        sed 's/<a href=\"\/problemset\/task\///g' |
        sed 's/<\/a>//g' |
        sed 's/\">/_/g'
}

solve_problems() {
    find . -maxdepth 1 -type d | grep -P -o './\d+' | sed 's/.\///g'
}

unresolved_problems() {
    echo ""
}

print() {
    while read PROBLEM; do echo $PROBLEM; done
}

all_problems
