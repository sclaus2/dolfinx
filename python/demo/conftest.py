import pytest


import pytest


def pytest_addoption(parser):
    parser.addoption("--mpiexec", action="store", default="mpirun",
                     help="Name of program to run MPI, e.g. mpiexex")
    parser.addoption("--num-proc", action="store", default=1,
                     help="Number of MPI processes to use")
    parser.addoption("--mpi-options", action="store",
                     help="Additional MPI options to use")


@pytest.fixture
def mpiexec(request):
    return request.config.getoption("--mpiexec")


@pytest.fixture
def mpioptions(request):
    return request.config.getoption("--mpi-options")


@pytest.fixture
def num_proc(request):
    return request.config.getoption("--num-proc")
