#include "encountertabledelegates.h"
#include "encountertablemodel.h"

#include <QSpinBox>
#include "project.h"
#include "noscrollcombobox.h"



SpeciesComboDelegate::SpeciesComboDelegate(Project *project, QObject *parent) : QStyledItemDelegate(parent) {
    this->project = project;
}

void SpeciesComboDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    const QString species = index.data(Qt::DisplayRole).toString();
    const QPixmap monIcon = this->project->getSpeciesIcon("SPECIES_" + species);
    painter->drawText(QRect(option.rect.topLeft() + QPoint(36, 0), option.rect.bottomRight()), Qt::AlignLeft | Qt::AlignVCenter, species);
    painter->drawPixmap(QRect(option.rect.topLeft(), QSize(32, 32)), monIcon, monIcon.rect());
}

QWidget *SpeciesComboDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &) const {
    NoScrollComboBox *editor = new NoScrollComboBox(parent);
    editor->setFrame(false);
    editor->addItems(this->project->speciesNames);
    return editor;
}

void SpeciesComboDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    QString species = index.data(Qt::EditRole).toString();
    NoScrollComboBox *combo = static_cast<NoScrollComboBox *>(editor);
    combo->setTextItem(species);
}

void SpeciesComboDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {
    NoScrollComboBox *combo = static_cast<NoScrollComboBox *>(editor);
    QString species = combo->currentText();
    model->setData(index, species, Qt::EditRole);
}

void SpeciesComboDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &) const {
    editor->setGeometry(option.rect);
}



SpinBoxDelegate::SpinBoxDelegate(Project *project, QObject *parent) : QStyledItemDelegate(parent) {
    this->project = project;
}

QWidget *SpinBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &index) const {
    QSpinBox *editor = new QSpinBox(parent);
    editor->setFrame(false);

    int col = index.column();
    if (col == EncounterTableModel::ColumnType::EncounterRate) {
        editor->setMinimum(0);
        editor->setMaximum(this->project->maxEncounterRate);
    }

    return editor;
}

void SpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    int value = index.model()->data(index, Qt::EditRole).toInt();

    QSpinBox *spinBox = static_cast<QSpinBox *>(editor);
    spinBox->setValue(value);
}

void SpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->interpretText();
    int value = spinBox->value();
    model->setData(index, value, Qt::EditRole);
}

void SpinBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &) const {
    editor->setGeometry(option.rect);
}
