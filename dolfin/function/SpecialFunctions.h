// Copyright (C) 2006-2008 Anders Logg.
// Licensed under the GNU LGPL Version 2.1.
//
// Modified by Kristian B. Oelgaard, 2007.
// Modified by Martin Sandve Alnes, 2008.
// Modified by Garth N. Wells, 2008.
//
// First added:  2006-02-09
// Last changed: 2008-11-03

#ifndef __SPECIAL_FUNCTIONS_H
#define __SPECIAL_FUNCTIONS_H

#include <vector>
#include <dolfin/fem/UFC.h>
#include "Function.h"

namespace dolfin
{

  class Form;
  class UFC;
  class FunctionSpace;
  class SubFunction;
  class Data;


  /// This Function represents the local mesh size on a given mesh.
  class MeshSize : public Function
  {
  public:

    /// Constructor
    MeshSize();

    /// Constructor
    MeshSize(const FunctionSpace& V);

    /// Function evaluation
    void eval(double* values, const Data& data) const;
    
    /// Compute minimal cell diameter
    double min() const;

    /// Compute maximal cell diameter
    double max() const;    

  };

  /// This Function represents the inverse of the local cell size on a given 
  /// mesh.
  class InvMeshSize : public Function
  {
  public:

    /// Constructor
    InvMeshSize();

    /// Constructor
    InvMeshSize(const FunctionSpace& V);

    /// Function evaluation
    void eval(double* values, const Data& data) const;

  };

  /// This Function represents the average of the local cell size (average of 
  /// cell sharing a facet) on a given mesh.
  class AvgMeshSize : public Function
  {
  public:

    /// Constructor
    AvgMeshSize();

    /// Constructor
    AvgMeshSize(const FunctionSpace& V);

    /// Function evaluation
    void eval(double* values, const Data& data) const;

  };

  /// This Function represents the outward unit normal on cell facets.
  /// Note that it is only nonzero on cell facets (not on cells).
  class FacetNormal : public Function
  {
  public:

    /// Constructor
    FacetNormal();

    /// Constructor
    FacetNormal(const FunctionSpace& V);

    /// Function evaluation
    void eval(double* values, const Data& data) const;
    
    uint rank() const;
    
    uint dim(uint i) const;

  };

  /// This function represents the area/length of a cell facet.
  class FacetArea : public Function
  {
  public:

    /// Constructor
    FacetArea();

    /// Constructor
    FacetArea(const FunctionSpace& V);

    /// Function evaluation
    void eval(double* values, const Data& data) const;

  };

  /// This function represents the inverse area/length of a cell facet.
  class InvFacetArea : public Function
  {
  public:

    /// Constructor
    InvFacetArea();

    /// Constructor
    InvFacetArea(const FunctionSpace& V);

    /// Function evaluation
    void eval(double* values, const Data& data) const;

  };

  /// This function determines if the current facet is an outflow facet with
  /// respect to the current cell. It accepts as argument the mesh and a form
  /// M = dot(n, v)*ds, a functional, defined on the normal vector to the
  /// facet and velocity vector integrated over the exterior of the cell.
  /// The function returns 1.0 if the dot product > 0, 0.0 otherwise.

  class IsOutflowFacet : public Function
  {
  public:

    // Constructor
    IsOutflowFacet(const FunctionSpace& V, const Function& f);

    ~IsOutflowFacet();

    void eval(double* values, const Data& data) const;

  private:

    const Function* field;
  };
  
  /// This function is used for the Python interface. By inheriting
  /// from this function instead of dolfin::Function, we avoid unnecessary
  /// calls through the SWIG created director class, when dealing
  /// with discrete functions in PyDOLFIN.
  class DiscreteFunction : public Function
  {
  public:

    // Constructor
    DiscreteFunction() : Function(){}
    
    // Constructor
    DiscreteFunction(const FunctionSpace& V) : Function(V)
    {
      vector();
    }
    
    // Constructor
    DiscreteFunction(const FunctionSpace& V, std::string filename) : Function(V,filename){}

    // Constructor
    DiscreteFunction(const SubFunction& v) : Function(v){}

    // Constructor
    DiscreteFunction(std::string filename) : Function(filename){}

    ~DiscreteFunction(){}
  };
}

#endif
