// TODO: __example

#include <npe.h>
#include <typedefs.h>






#include <igl/fit_plane.h>

const char* ds_fit_plane = R"igl_Qu8mg5v7(

This function fits a plane to a point cloud.

Parameters
----------
V #Vx3 matrix. The 3D point cloud, one row for each vertex.

Returns
-------
N 1x3 Vector. The normal of the fitted plane.
C 1x3 Vector. A point that lies in the fitted plane.

See also
--------

Notes
-----
From http:missingbytes.blogspot.com/2012/06/fitting-plane-to-point-cloud.html

Examples
--------

  
)igl_Qu8mg5v7";

npe_function(fit_plane)
npe_doc(ds_fit_plane)

npe_arg(v, dense_float, dense_double)


npe_begin_code()

  // TODO: remove __copy
  Eigen::MatrixXd v_copy = v.template cast<double>();
  Eigen::RowVector3d n;
  Eigen::RowVector3d c;
  igl::fit_plane(v_copy, n, c);
  return std::make_tuple(npe::move(n), npe::move(c));

npe_end_code()

