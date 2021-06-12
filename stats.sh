#!/bin/env bash
set -o pipefail

DB_FILE="stats.sqlite"

function usage()
{
  echo "Usage: $(basename "$0") <lng>"
  echo "    lng est un nombre entier > 1"
}

function init()
{
  echo ".schema" | sqlite3 "${DB_FILE}" &>/dev/null
  if [[ $? -ne 0 ]]
  then
    echo "Initialisation de la base de données échouée" >&2
    exit 1
  fi

  echo ".schema" | sqlite3 "${DB_FILE}" | grep -q "CREATE TABLE sort_stats"
  if [[ $? -ne 0 ]]
  then
    echo "CREATE TABLE sort_stats (id INTEGER PRIMARY KEY, lng INTEGER NOT NULL, tries INTEGER NOT NULL);" | sqlite3 "${DB_FILE}"
  fi
}

function run-once()
{
  ./random-sort 5 | grep Triée | awk '{print $3}'
}

function main()
{
  local ARRAY_SIZE="$1"
  if [[ ! "$ARRAY_SIZE" -gt 0 ]]
  then
    usage
    exit 1
  fi

  init

  for i in {1..10000}
  do
    echo "Run $i"
    TRIES="$(run-once "$ARRAY_SIZE")"
    echo "INSERT INTO sort_stats(lng, tries) VALUES ($ARRAY_SIZE, $TRIES);" | sqlite3 "${DB_FILE}"
  done
}

main "$@"