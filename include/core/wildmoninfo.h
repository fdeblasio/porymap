#pragma once
#ifndef GUARD_WILDMONINFO_H
#define GUARD_WILDMONINFO_H

#include <QtWidgets>
#include "orderedmap.h"

struct WildPokemon {
    QString range = "5, 5";
    QString species = "NONE";
};

struct WildMonInfo {
    bool active = false;
    int encounterRate = 0;
    QVector<WildPokemon> wildPokemon;
};

struct WildPokemonHeader {
    tsl::ordered_map<QString, WildMonInfo> wildMons;
};

struct EncounterField {
    QString name;
    QVector<int> encounterRates;
    tsl::ordered_map<QString, QVector<int>> groups;
};

typedef QVector<EncounterField> EncounterFields;

void setDefaultEncounterRate(QString fieldName, int rate);
WildMonInfo getDefaultMonInfo(EncounterField field);
void combineEncounters(WildMonInfo &to, WildMonInfo from);

#endif // GUARD_WILDMONINFO_H
