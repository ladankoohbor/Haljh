/* This file is automatically generated from the documentation. EDIT AT YOUR OWN RISK. */

#ifndef PROOT_CLI_H
#define PROOT_CLI_H

#include "cli/cli.h"

#ifndef VERSION
#define VERSION "5.1.0"
#endif

static const char *recommended_bindings[] = {
	"/etc/host.conf",
	"/etc/hosts",
	"/etc/hosts.equiv",
	"/etc/mtab",
	"/etc/netgroup",
	"/etc/networks",
	"/etc/passwd",
	"/etc/group",
	"/etc/nsswitch.conf",
	"/etc/resolv.conf",
	"/etc/localtime",
	"/dev/",
	"/sys/",
	"/proc/",
	"/tmp/",
	"/run/",
	"/var/run/dbus/system_bus_socket",
/*	"/var/tmp/kdecache-$LOGNAME", */
	"$HOME",
	"*path*",
	NULL,
};

static const char *recommended_su_bindings[] = {
	"/etc/host.conf",
	"/etc/hosts",
	"/etc/nsswitch.conf",
	"/etc/resolv.conf",
	"/dev/",
	"/sys/",
	"/proc/",
	"/tmp/",
	"/run/shm",
	"$HOME",
	"*path*",
	NULL,
};

static int handle_option_r(Tracee *tracee, const Cli *cli, const char *value);
static int handle_option_b(Tracee *tracee, const Cli *cli, const char *value);
static int handle_option_q(Tracee *tracee, const Cli *cli, const char *value);
static int handle_option_w(Tracee *tracee, const Cli *cli, const char *value);
static int handle_option_v(Tracee *tracee, const Cli *cli, const char *value);
static int handle_option_V(Tracee *tracee, const Cli *cli, const char *value);
static int handle_option_h(Tracee *tracee, const Cli *cli, const char *value);
static int handle_option_k(Tracee *tracee, const Cli *cli, const char *value);
static int handle_option_0(Tracee *tracee, const Cli *cli, const char *value);
static int handle_option_l(Tracee *tracee, const Cli *cli, const char *value);
static int handle_option_L(Tracee *tracee, const Cli *cli, const char *value);
static int handle_option_H(Tracee *tracee, const Cli *cli, const char *value);
static int handle_option_p(Tracee *tracee, const Cli *cli, const char *value);
static int handle_option_i(Tracee *tracee, const Cli *cli, const char *value);
static int handle_option_R(Tracee *tracee, const Cli *cli, const char *value);
static int handle_option_S(Tracee *tracee, const Cli *cli, const char *value);
static int handle_option_kill_on_exit(Tracee *tracee, const Cli *cli, const char *value);

static int pre_initialize_bindings(Tracee *, const Cli *, size_t, char *const *, size_t);
static int post_initialize_exe(Tracee *, const Cli *, size_t, char *const *, size_t);

static Cli proot_cli = {
	.version  = VERSION,
	.name     = "proot",
	.subtitle = "chroot, mount --bind, and binfmt_misc without privilege/setup",
	.synopsis = "proot [option] ... [command]",
	.colophon = "Visit http://proot.me for help, bug reports, suggestions, patchs, ...\n\
Copyright (C) 2015 STMicroelectronics, licensed under GPL v2 or later.",
	.logo = "\
 _____ _____              ___\n\
|  __ \\  __ \\_____  _____|   |_\n\
|   __/     /  _  \\/  _  \\    _|\n\
|__|  |__|__\\_____/\\_____/\\____|",

	.pre_initialize_bindings = pre_initialize_bindings,
	.post_initialize_exe = post_initialize_exe,

	.options = {
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "-r", .separator = ' ', .value = "path" },
		{ .name = "--rootfs", .separator = '=', .value = "path" },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_r,
	  .description = "Use *path* as the new guest root file-system, default is /.",
	  .detail = "\tThe specified path typically contains a Linux distribution where\n\
\tall new programs will be confined.  The default rootfs is /\n\
\twhen none is specified, this makes sense when the bind mechanism\n\
\tis used to relocate host files and directories, see the -b\n\
\toption and the Examples section for details.\n\
\t\n\
\tIt is recommended to use the -R or -S options instead.",
	},
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "-b", .separator = ' ', .value = "path" },
		{ .name = "--bind", .separator = '=', .value = "path" },
		{ .name = "-m", .separator = ' ', .value = "path" },
		{ .name = "--mount", .separator = '=', .value = "path" },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_b,
	  .description = "Make the content of *path* accessible in the guest rootfs.",
	  .detail = "\tThis option makes any file or directory of the host rootfs\n\
\taccessible in the confined environment just as if it were part of\n\
\tthe guest rootfs.  By default the host path is bound to the same\n\
\tpath in the guest rootfs but users can specify any other location\n\
\twith the syntax: -b *host_path*:*guest_location*.  If the\n\
\tguest location is a symbolic link, it is dereferenced to ensure\n\
\tthe new content is accessible through all the symbolic links that\n\
\tpoint to the overlaid content.  In most cases this default\n\
\tbehavior shouldn't be a problem, although it is possible to\n\
\texplicitly not dereference the guest location by appending it the\n\
\t! character: -b *host_path*:*guest_location!*.",
	},
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "-q", .separator = ' ', .value = "command" },
		{ .name = "--qemu", .separator = '=', .value = "command" },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_q,
	  .description = "Execute guest programs through QEMU as specified by *command*.",
	  .detail = "\tEach time a guest program is going to be executed, PRoot inserts\n\
\tthe QEMU user-mode command in front of the initial request.\n\
\tThat way, guest programs actually run on a virtual guest CPU\n\
\temulated by QEMU user-mode.  The native execution of host programs\n\
\tis still effective and the whole host rootfs is bound to\n\
\t/host-rootfs in the guest environment.",
	},
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "-w", .separator = ' ', .value = "path" },
		{ .name = "--pwd", .separator = '=', .value = "path" },
		{ .name = "--cwd", .separator = '=', .value = "path" },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_w,
	  .description = "Set the initial working directory to *path*.",
	  .detail = "\tSome programs expect to be launched from a given directory but do\n\
\tnot perform any chdir by themselves.  This option avoids the\n\
\tneed for running a shell and then entering the directory manually.",
	},
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "--kill-on-exit", .separator = '\0', .value = NULL },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_kill_on_exit,
	  .description = "Kill all processes on command exit.",
	  .detail = "\tWhen the executed command leaves orphean or detached processes\n\
\taround, proot waits until all processes possibly terminate. This option forces\n\
\tthe immediate termination of all tracee processes when the main command exits.",
	},
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "-v", .separator = ' ', .value = "value" },
		{ .name = "--verbose", .separator = '=', .value = "value" },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_v,
	  .description = "Set the level of debug information to *value*.",
	  .detail = "\tThe higher the integer value is, the more detailed debug\n\
\tinformation is printed to the standard error stream.  A negative\n\
\tvalue makes PRoot quiet except on fatal errors.",
	},
        { .class = "Regular options",
          .arguments = {
                { .name = "-H", .separator = '\0', .value = NULL },
                { .name = NULL, .separator = '\0', .value = NULL } },
          .handler = handle_option_H,
          .description = "Hide files and directories starting with '.proot.' .",
          .detail = "",
        },
        { .class = "Regular options",
          .arguments = {
                { .name = "-p", .separator = '\0', .value = NULL },
                { .name = NULL, .separator = '\0', .value = NULL } },
          .handler = handle_option_p,
          .description = "Modify bindings to protected ports to use a higher port number.",
          .detail = "",
        },
        { .class = "Regular options",
          .arguments = {
                { .name = "-l", .separator = '\0', .value = NULL },
                { .name = NULL, .separator = '\0', .value = NULL } },
          .handler = handle_option_l,
          .description = "Convert hard links to be symbolic links.",
          .detail = "",
        },
        { .class = "Regular options",
          .arguments = {
                { .name = "-L", .separator = '\0', .value = NULL },
                { .name = NULL, .separator = '\0', .value = NULL } },
          .handler = handle_option_L,
          .description = "Correct the size returned from lstat for symbolic links.",
          .detail = "",
        },
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "-V", .separator = '\0', .value = NULL },
		{ .name = "--version", .separator = '\0', .value = NULL },
		{ .name = "--about", .separator = '\0', .value = NULL },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_V,
	  .description = "Print version, copyright, license and contact, then exit.",
	  .detail = "",
	},
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "-h", .separator = '\0', .value = NULL },
		{ .name = "--help", .separator = '\0', .value = NULL },
		{ .name = "--usage", .separator = '\0', .value = NULL },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_h,
	  .description = "Print the version and the command-line usage, then exit.",
	  .detail = "",
	},
	{ .class = "Extension options",
	  .arguments = {
		{ .name = "-k", .separator = ' ', .value = "string" },
		{ .name = "--kernel-release", .separator = '=', .value = "string" },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_k,
	  .description = "Make current kernel appear as kernel release *string*.",
	  .detail = "\tIf a program is run on a kernel older than the one expected by its\n\
\tGNU C library, the following error is reported: \"FATAL: kernel too\n\
\told\".  To be able to run such programs, PRoot can emulate some of\n\
\tthe features that are available in the kernel release specified by\n\
\t*string* but that are missing in the current kernel.",
	},
	{ .class = "Extension options",
	  .arguments = {
		{ .name = "-0", .separator = '\0', .value = NULL },
		{ .name = "--root-id", .separator = '\0', .value = NULL },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_0,
	  .description = "Make current user appear as \"root\" and fake its privileges.",
	  .detail = "\tSome programs will refuse to work if they are not run with \"root\"\n\
\tprivileges, even if there is no technical reason for that.  This\n\
\tis typically the case with package managers.  This option allows\n\
\tusers to bypass this kind of limitation by faking the user/group\n\
\tidentity, and by faking the success of some operations like\n\
\tchanging the ownership of files, changing the root directory to\n\
\t/, ...  Note that this option is quite limited compared to\n\
\tfakeroot.",
	},
	{ .class = "Extension options",
	  .arguments = {
		{ .name = "-i", .separator = ' ', .value = "string" },
		{ .name = "--change-id", .separator = '=', .value = "string" },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_i,
	  .description = "Make current user and group appear as *string* \"uid:gid\".",
	  .detail = "\tThis option makes the current user and group appear as uid and\n\
\tgid.  Likewise, files actually owned by the current user and\n\
\tgroup appear as if they were owned by uid and gid instead.\n\
\tNote that the -0 option is the same as -i 0:0.",
	},
	{ .class = "Alias options",
	  .arguments = {
		{ .name = "-R", .separator = ' ', .value = "path" },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_R,
	  .description = "Alias: -r *path* + a couple of recommended -b.",
	  .detail = "\tPrograms isolated in *path*, a guest rootfs, might still need to\n\
\taccess information about the host system, as it is illustrated in\n\
\tthe Examples section of the manual.  These host information\n\
\tare typically: user/group definition, network setup, run-time\n\
\tinformation, users' files, ...  On all Linux distributions, they\n\
\tall lie in a couple of host files and directories that are\n\
\tautomatically bound by this option:\n\
\t\n\
\t    * /etc/host.conf\n\
\t    * /etc/hosts\n\
\t    * /etc/hosts.equiv\n\
\t    * /etc/mtab\n\
\t    * /etc/netgroup\n\
\t    * /etc/networks\n\
\t    * /etc/passwd\n\
\t    * /etc/group\n\
\t    * /etc/nsswitch.conf\n\
\t    * /etc/resolv.conf\n\
\t    * /etc/localtime\n\
\t    * /dev/\n\
\t    * /sys/\n\
\t    * /proc/\n\
\t    * /tmp/\n\
\t    * /run/\n\
\t    * /var/run/dbus/system_bus_socket\n\
\t    * $HOME",
	},
	{ .class = "Alias options",
	  .arguments = {
		{ .name = "-S", .separator = ' ', .value = "path" },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_S,
	  .description = "Alias: -0 -r *path* + a couple of recommended -b.",
	  .detail = "\tThis option is useful to safely create and install packages into\n\
\tthe guest rootfs.  It is similar to the -R option expect it\n\
\tenables the -0 option and binds only the following minimal set\n\
\tof paths to avoid unexpected changes on host files:\n\
\t\n\
\t    * /etc/host.conf\n\
\t    * /etc/hosts\n\
\t    * /etc/nsswitch.conf\n\
\t    * /etc/resolv.conf\n\
\t    * /dev/\n\
\t    * /sys/\n\
\t    * /proc/\n\
\t    * /tmp/\n\
\t    * /run/shm\n\
\t    * $HOME",
	},
	END_OF_OPTIONS,
	},
};

#endif /* PROOT_CLI_H */
