// -*- C++ -*-
#ifndef RIVET_HeavyHadrons_HH
#define RIVET_HeavyHadrons_HH

#include "Rivet/Projections/FinalState.hh"
#include "Rivet/Projections/UnstableFinalState.hh"
#include "Rivet/Particle.hh"
#include "Rivet/Event.hh"

namespace Rivet {


  /// @brief Project out the last pre-decay b and c hadrons.
  ///
  /// This currently defines a c-hadron as one which contains a @a c quark and
  /// @a{not} a @a b quark.
  ///
  /// @todo This assumes that the heavy hadrons are unstable... should we also look for stable ones in case the decays are disabled?
  class HeavyHadrons : public FinalState {
  public:

    /// @name Constructors and destructors.
    //@{

    /// Constructor with specification of the minimum and maximum pseudorapidity
    /// \f$ \eta \f$ and the min \f$ p_T \f$ (in GeV).
    HeavyHadrons(const Cut& c=Cuts::open()) {
      setName("HeavyHadrons");
      addProjection(UnstableFinalState(c), "UFS");
    }

    /// Constructor with specification of the minimum and maximum pseudorapidity
    /// \f$ \eta \f$ and the min \f$ p_T \f$ (in GeV).
    DEPRECATED("Use the version with a Cut argument")
    HeavyHadrons(double mineta, double maxeta, double minpt=0.0*GeV) {
      setName("HeavyHadrons");
      addProjection(UnstableFinalState(Cuts::etaIn(mineta, maxeta) && Cuts::pT > minpt), "UFS");
    }

    /// Clone on the heap.
    DEFAULT_RIVET_PROJ_CLONE(HeavyHadrons);

    //@}


    /// @name Particle accessors
    //@{

    /// Get all weakly decaying b hadrons (return by reference)
    const Particles& bHadrons() const {
      return _theBs;
    }

    /// Get weakly decaying b hadrons with a pTmin cut (return by value)
    Particles bHadrons(double pTmin) const {
      Particles rtn;
      foreach (const Particle& p, bHadrons())
        if (p.pT() > pTmin) rtn += p;
      return rtn;
    }

    /// Get all weakly decaying c hadrons (return by reference)
    const Particles& cHadrons() const {
      return _theCs;
    }

    /// Get weakly decaying c hadrons with a pTmin cut (return by value)
    const Particles cHadrons(double pTmin) const {
      Particles rtn;
      foreach (const Particle& p, cHadrons())
        if (p.pT() > pTmin) rtn += p;
      return rtn;
    }

    //@}


  protected:

    /// Apply the projection to the event.
    virtual void project(const Event& e);

    /// Compare projections (only difference is in UFS definition)
    virtual int compare(const Projection& p) const {
      return mkNamedPCmp(p, "UFS");
    }

    /// b and c hadron containers
    Particles _theBs, _theCs;

  };


}


#endif
