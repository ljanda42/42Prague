#!/bin/bash

# Uložení aktuálního adresáře
ORIG_DIR=$(pwd)

# Nastavení trap, aby se vždy vrátilo zpět do původní složky
trap 'cd "$ORIG_DIR"' EXIT

# Přepnutí do složky s repozitářem
cd /media/sf_42Prague || exit 1

# Přidání změn
git add .
if [ $? -ne 0 ]; then
    echo "Chyba při git add."
    exit 1
fi

# Zkontroluj, zda je něco ke commitnutí
git diff --cached --quiet
if [ $? -eq 0 ]; then
    echo "Žádné změny ke commitnutí."
    exit 0
fi

# Commit se současným datem a časem
git commit -m "Backup from $(date '+%Y-%m-%d %H:%M:%S')"
if [ $? -ne 0 ]; then
    echo "Chyba při git commit."
    exit 1
fi

# Push do vzdáleného repozitáře
git push
if [ $? -ne 0 ]; then
    echo "Chyba při git push."
    exit 1
fi
