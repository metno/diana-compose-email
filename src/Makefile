
CXX = g++
CXXFLAGS = -Wall -W

CXXFLAGS += -W -Wall -g $(shell pkg-config --cflags QtGui QtCore)
LIBS      = $(shell pkg-config --libs   QtGui QtCore)

UIC = $(shell pkg-config --variable=uic_location QtGui)
RCC = $(shell pkg-config --variable=rcc_location QtGui)
MOC = $(shell pkg-config --variable=moc_location QtGui)
LUP = $(shell pkg-config --variable=lupdate_location QtGui)
LRL = $(shell pkg-config --variable=lrelease_location QtGui)

LANGUAGES = de es nb ru sv
TSFILES = $(LANGUAGES:%=compose_email_%.ts)
QMFILES = $(LANGUAGES:%=compose_email_%.qm)

ICONS = #do-not-send.svg send-mail.svg icon-crash.svg

OBJECTS = main.o compose_email.o attached_files_model.o compose_email_rcc.o compose_email_moc.o

DCE = diana_compose_email

all: $(DCE)

$(DCE): $(OBJECTS)
	$(CXX) -o $@ $^ $(LIBS)

#compose_email.o: compose_email.hh ui_compose_email.h

.cc.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

#ui_compose_email.h: compose_email.ui
#	$(UIC) -o $@ $<

compose_email_rcc.cc: compose_email.qrc $(ICONS) $(QMFILES)
	$(RCC) -o $@ $<

compose_email_moc.cc: compose_email.h attached_files_model.h #ui_compose_email.h
	$(MOC) -o$@ $<

lupdate $(TSFILES): main.cc compose_email.cc attached_files_model.cc # compose_email.ui
	$(LUP) $^ -ts $(TSFILES)

$(QMFILES): %.qm: %.ts
	$(LRL) $< -qm $@

clean:
	rm -f $(DCE) ui_compose_email.h $(OBJECTS) compose_email_rcc.cc compose_email_moc.cc $(QMFILES)

.PHONY: all clean lupdate
