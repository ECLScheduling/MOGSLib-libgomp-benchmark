#
# Copyright(C) 2016-2017 Pedro H. Penna <pedrohenriquepenna@gmail.com>
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
# MA 02110-1301, USA.
#

INPUT=$1
NTHREADS=$2
LOAD=$3
EXECUTIONS=$4

if [ -z $INPUT ]; then
	echo "missing input workload"
	exit -1
fi

if [ -z $NTHREADS ]; then
	echo "missing number of threads"
	exit -1
fi

if [ -z $LOAD ]; then
	#let LOAD=100000000
  let LOAD=1000000
fi

if [ -z $EXECUTIONS ]; then
	let EXECUTIONS=1
fi
for i in `seq 1 $EXECUTIONS`;
do
	echo "=== Run $i ==="
	for strategy in mogslib binlpt;
	do
		echo "=== $strategy ==="

		export LD_LIBRARY_PATH=contrib/libgomp/src/libgomp/build/.libs/
		export OMP_SCHEDULE="$strategy"
		export MOGSLIB_SCHEDULE="binlpt"
		export GOMP_CPU_AFFINITY="0-$NTHREADS"
		bin/benchmark.elf        \
			--input $INPUT       \
			--nthreads $NTHREADS \
			--kernel quadratic \
			--load $LOAD
	done
done
