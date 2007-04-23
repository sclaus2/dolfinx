// Copyright (C) 2003-2005 Anders Logg.
// Licensed under the GNU LGPL Version 2.1.
//
// First added:  2003-11-28
// Last changed: 2005

#ifndef __DUAL_H
#define __DUAL_H

#include <dolfin/ODE.h>

namespace dolfin {

  class RHS;

  /// A Dual represents an initial value problem of the form
  ///
  ///   - phi'(t) = J(u,t)^* phi(t) on [0,T),
  ///         
  ///     phi(T)  = psi,
  ///
  /// where phi(t) is a vector of length N, A is the Jacobian of the
  /// right-hand side f of the primal problem, and psi is given final
  /// time data for the dual.
  ///
  /// To solve the Dual forward in time, it is rewritten using the
  /// substitution t -> T - t, i.e. we solve an initial value problem
  /// of the form
  ///
  ///     w'(t) = J(u(T-t),T-t)^* w(t) on (0,T],
  ///         
  ///     w(0)  = psi,
  ///
  /// where w(t) = phi(T-t).

  // FIXME: BROKEN

  class Dual : public ODE
  {
  public:

    Dual() : ODE(1, 1.0) {}

    /// Constructor
    //Dual(ODE& primal);
    //Dual(ODE& primal, Function& u);

    /// Destructor
    //~Dual();

    /// Initial value
    //real u0(unsigned int i);

    /// Right-hand side
    //real f(const Vector& phi, real t, unsigned int i);

  private:

    // Right-hand side for primal problem
    //RHS rhs;

  };

}

#endif
