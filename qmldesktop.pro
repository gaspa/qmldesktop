QT       += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = subdirs

SUBDIRS += \
    app  \
    #tests

tests.depends = app 
