#pragma once

#include <pybind11/pybind11.h>
#include <torch/csrc/autograd/saved_variable_hooks.h>
#include <torch/csrc/python_headers.h>
#include <torch/csrc/utils/auto_gil.h>

#include <ATen/ATen.h>

namespace py = pybind11;

namespace torch { namespace autograd {

struct TORCH_API PySavedVariableHooks : public SavedVariableHooks {
  // PySavedVariableHooks(py::function &pack_hook, py::function &unpack_hook);
  PySavedVariableHooks(PyObject* pack_hook, PyObject* unpack_hook);
  PyObject* call_pack_hook(at::Tensor tensor) override;
  at::Tensor call_unpack_hook(PyObject* obj) override;

private:
  // py::function pack_hook_;
  // py::function unpack_hook_;
  PyObject* pack_hook_;
  PyObject* unpack_hook_;
};

}}
