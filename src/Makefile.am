SUBDIRS = Core Tools Projections
SUBDIRS += Analyses
ANA_LIBADD = Analyses/libRivetAnalysisTools.la

lib_LTLIBRARIES = libRivet.la
libRivet_la_SOURCES =
libRivet_la_LDFLAGS = -export-dynamic -avoid-version -L$(YODALIBPATH) -L$(HEPMCLIBPATH)
libRivet_la_LIBADD = Core/libRivetCore.la Projections/libRivetProjections.la Tools/libRivetTools.la $(ANA_LIBADD) \
  -lYODA -lHepMC -ldl -lm  $(FASTJETCONFIGLIBADD) $(GSL_LDFLAGS)
