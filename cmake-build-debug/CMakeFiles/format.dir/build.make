# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/hog/.cache/JetBrains/RemoteDev/dist/68305831d57ea_CLion-2022.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/hog/.cache/JetBrains/RemoteDev/dist/68305831d57ea_CLion-2022.2.4/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hog/cs144/lab0/sponge

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hog/cs144/lab0/sponge/cmake-build-debug

# Utility rule file for format.

# Include any custom commands dependencies for this target.
include CMakeFiles/format.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/format.dir/progress.make

CMakeFiles/format:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/hog/cs144/lab0/sponge/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Formatted all source files."
	clang-format-6.0 -i /home/hog/cs144/lab0/sponge/apps/bidirectional_stream_copy.cc /home/hog/cs144/lab0/sponge/apps/tcp_benchmark.cc /home/hog/cs144/lab0/sponge/apps/tcp_ip_ethernet.cc /home/hog/cs144/lab0/sponge/apps/tcp_ipv4.cc /home/hog/cs144/lab0/sponge/apps/tcp_native.cc /home/hog/cs144/lab0/sponge/apps/tcp_udp.cc /home/hog/cs144/lab0/sponge/apps/tun.cc /home/hog/cs144/lab0/sponge/apps/udp_tcpdump.cc /home/hog/cs144/lab0/sponge/apps/webget.cc /home/hog/cs144/lab0/sponge/doctests/address_dt.cc /home/hog/cs144/lab0/sponge/doctests/address_example_1.cc /home/hog/cs144/lab0/sponge/doctests/address_example_2.cc /home/hog/cs144/lab0/sponge/doctests/address_example_3.cc /home/hog/cs144/lab0/sponge/doctests/parser_dt.cc /home/hog/cs144/lab0/sponge/doctests/parser_example.cc /home/hog/cs144/lab0/sponge/doctests/socket_dt.cc /home/hog/cs144/lab0/sponge/doctests/socket_example_1.cc /home/hog/cs144/lab0/sponge/doctests/socket_example_2.cc /home/hog/cs144/lab0/sponge/doctests/socket_example_3.cc /home/hog/cs144/lab0/sponge/libsponge/byte_stream.cc /home/hog/cs144/lab0/sponge/libsponge/network_interface.cc /home/hog/cs144/lab0/sponge/libsponge/stream_reassembler.cc /home/hog/cs144/lab0/sponge/libsponge/tcp_connection.cc /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/arp_message.cc /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/ethernet_frame.cc /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/ethernet_header.cc /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/fd_adapter.cc /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/ipv4_datagram.cc /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/ipv4_header.cc /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/tcp_header.cc /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/tcp_over_ip.cc /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/tcp_segment.cc /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/tcp_sponge_socket.cc /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/tcp_state.cc /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/tuntap_adapter.cc /home/hog/cs144/lab0/sponge/libsponge/tcp_receiver.cc /home/hog/cs144/lab0/sponge/libsponge/tcp_sender.cc /home/hog/cs144/lab0/sponge/libsponge/util/address.cc /home/hog/cs144/lab0/sponge/libsponge/util/buffer.cc /home/hog/cs144/lab0/sponge/libsponge/util/eventloop.cc /home/hog/cs144/lab0/sponge/libsponge/util/file_descriptor.cc /home/hog/cs144/lab0/sponge/libsponge/util/parser.cc /home/hog/cs144/lab0/sponge/libsponge/util/socket.cc /home/hog/cs144/lab0/sponge/libsponge/util/tun.cc /home/hog/cs144/lab0/sponge/libsponge/util/util.cc /home/hog/cs144/lab0/sponge/libsponge/wrapping_integers.cc /home/hog/cs144/lab0/sponge/tests/byte_stream_capacity.cc /home/hog/cs144/lab0/sponge/tests/byte_stream_construction.cc /home/hog/cs144/lab0/sponge/tests/byte_stream_many_writes.cc /home/hog/cs144/lab0/sponge/tests/byte_stream_one_write.cc /home/hog/cs144/lab0/sponge/tests/byte_stream_test_harness.cc /home/hog/cs144/lab0/sponge/tests/byte_stream_two_writes.cc /home/hog/cs144/lab0/sponge/tests/fsm_ack_rst.cc /home/hog/cs144/lab0/sponge/tests/fsm_ack_rst_relaxed.cc /home/hog/cs144/lab0/sponge/tests/fsm_ack_rst_win.cc /home/hog/cs144/lab0/sponge/tests/fsm_ack_rst_win_relaxed.cc /home/hog/cs144/lab0/sponge/tests/fsm_active_close.cc /home/hog/cs144/lab0/sponge/tests/fsm_connect.cc /home/hog/cs144/lab0/sponge/tests/fsm_connect_relaxed.cc /home/hog/cs144/lab0/sponge/tests/fsm_listen.cc /home/hog/cs144/lab0/sponge/tests/fsm_listen_relaxed.cc /home/hog/cs144/lab0/sponge/tests/fsm_loopback.cc /home/hog/cs144/lab0/sponge/tests/fsm_loopback_win.cc /home/hog/cs144/lab0/sponge/tests/fsm_passive_close.cc /home/hog/cs144/lab0/sponge/tests/fsm_reorder.cc /home/hog/cs144/lab0/sponge/tests/fsm_retx.cc /home/hog/cs144/lab0/sponge/tests/fsm_retx_relaxed.cc /home/hog/cs144/lab0/sponge/tests/fsm_retx_win.cc /home/hog/cs144/lab0/sponge/tests/fsm_stream_reassembler_cap.cc /home/hog/cs144/lab0/sponge/tests/fsm_stream_reassembler_dup.cc /home/hog/cs144/lab0/sponge/tests/fsm_stream_reassembler_holes.cc /home/hog/cs144/lab0/sponge/tests/fsm_stream_reassembler_many.cc /home/hog/cs144/lab0/sponge/tests/fsm_stream_reassembler_overlapping.cc /home/hog/cs144/lab0/sponge/tests/fsm_stream_reassembler_seq.cc /home/hog/cs144/lab0/sponge/tests/fsm_stream_reassembler_single.cc /home/hog/cs144/lab0/sponge/tests/fsm_stream_reassembler_win.cc /home/hog/cs144/lab0/sponge/tests/fsm_winsize.cc /home/hog/cs144/lab0/sponge/tests/ipv4_parser.cc /home/hog/cs144/lab0/sponge/tests/net_interface.cc /home/hog/cs144/lab0/sponge/tests/network_interface_test_harness.cc /home/hog/cs144/lab0/sponge/tests/recv_close.cc /home/hog/cs144/lab0/sponge/tests/recv_connect.cc /home/hog/cs144/lab0/sponge/tests/recv_reorder.cc /home/hog/cs144/lab0/sponge/tests/recv_special.cc /home/hog/cs144/lab0/sponge/tests/recv_transmit.cc /home/hog/cs144/lab0/sponge/tests/recv_window.cc /home/hog/cs144/lab0/sponge/tests/send_ack.cc /home/hog/cs144/lab0/sponge/tests/send_close.cc /home/hog/cs144/lab0/sponge/tests/send_connect.cc /home/hog/cs144/lab0/sponge/tests/send_equivalence_checker.cc /home/hog/cs144/lab0/sponge/tests/send_extra.cc /home/hog/cs144/lab0/sponge/tests/send_retx.cc /home/hog/cs144/lab0/sponge/tests/send_transmit.cc /home/hog/cs144/lab0/sponge/tests/send_window.cc /home/hog/cs144/lab0/sponge/tests/tcp_fsm_test_harness.cc /home/hog/cs144/lab0/sponge/tests/tcp_parser.cc /home/hog/cs144/lab0/sponge/tests/wrapping_integers_cmp.cc /home/hog/cs144/lab0/sponge/tests/wrapping_integers_roundtrip.cc /home/hog/cs144/lab0/sponge/tests/wrapping_integers_unwrap.cc /home/hog/cs144/lab0/sponge/tests/wrapping_integers_wrap.cc /home/hog/cs144/lab0/sponge/apps/bidirectional_stream_copy.hh /home/hog/cs144/lab0/sponge/libsponge/byte_stream.hh /home/hog/cs144/lab0/sponge/libsponge/network_interface.hh /home/hog/cs144/lab0/sponge/libsponge/stream_reassembler.hh /home/hog/cs144/lab0/sponge/libsponge/tcp_connection.hh /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/arp_message.hh /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/ethernet_frame.hh /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/ethernet_header.hh /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/fd_adapter.hh /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/ipv4_datagram.hh /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/ipv4_header.hh /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/lossy_fd_adapter.hh /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/tcp_config.hh /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/tcp_header.hh /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/tcp_over_ip.hh /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/tcp_segment.hh /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/tcp_sponge_socket.hh /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/tcp_state.hh /home/hog/cs144/lab0/sponge/libsponge/tcp_helpers/tuntap_adapter.hh /home/hog/cs144/lab0/sponge/libsponge/tcp_receiver.hh /home/hog/cs144/lab0/sponge/libsponge/tcp_sender.hh /home/hog/cs144/lab0/sponge/libsponge/util/address.hh /home/hog/cs144/lab0/sponge/libsponge/util/buffer.hh /home/hog/cs144/lab0/sponge/libsponge/util/eventloop.hh /home/hog/cs144/lab0/sponge/libsponge/util/file_descriptor.hh /home/hog/cs144/lab0/sponge/libsponge/util/parser.hh /home/hog/cs144/lab0/sponge/libsponge/util/socket.hh /home/hog/cs144/lab0/sponge/libsponge/util/tun.hh /home/hog/cs144/lab0/sponge/libsponge/util/util.hh /home/hog/cs144/lab0/sponge/libsponge/wrapping_integers.hh /home/hog/cs144/lab0/sponge/tests/byte_stream_test_harness.hh /home/hog/cs144/lab0/sponge/tests/fsm_retx.hh /home/hog/cs144/lab0/sponge/tests/fsm_stream_reassembler_harness.hh /home/hog/cs144/lab0/sponge/tests/network_interface_test_harness.hh /home/hog/cs144/lab0/sponge/tests/receiver_harness.hh /home/hog/cs144/lab0/sponge/tests/send_equivalence_checker.hh /home/hog/cs144/lab0/sponge/tests/sender_harness.hh /home/hog/cs144/lab0/sponge/tests/string_conversions.hh /home/hog/cs144/lab0/sponge/tests/tcp_expectation.hh /home/hog/cs144/lab0/sponge/tests/tcp_expectation_forward.hh /home/hog/cs144/lab0/sponge/tests/tcp_fsm_test_harness.hh /home/hog/cs144/lab0/sponge/tests/test_err_if.hh /home/hog/cs144/lab0/sponge/tests/test_should_be.hh /home/hog/cs144/lab0/sponge/tests/test_utils.hh /home/hog/cs144/lab0/sponge/tests/test_utils_ipv4.hh

format: CMakeFiles/format
format: CMakeFiles/format.dir/build.make
.PHONY : format

# Rule to build all files generated by this target.
CMakeFiles/format.dir/build: format
.PHONY : CMakeFiles/format.dir/build

CMakeFiles/format.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/format.dir/cmake_clean.cmake
.PHONY : CMakeFiles/format.dir/clean

CMakeFiles/format.dir/depend:
	cd /home/hog/cs144/lab0/sponge/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hog/cs144/lab0/sponge /home/hog/cs144/lab0/sponge /home/hog/cs144/lab0/sponge/cmake-build-debug /home/hog/cs144/lab0/sponge/cmake-build-debug /home/hog/cs144/lab0/sponge/cmake-build-debug/CMakeFiles/format.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/format.dir/depend

