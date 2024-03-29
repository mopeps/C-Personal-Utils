const std = @import("std");

pub fn build(b: *std.Build) void {
    const optimization = b.standardOptimizeOption(.{});
    const target = b.standardTargetOptions(.{});
    const exe = b.addExecutable(.{ .name = "c-personal-utils", .optimize = optimization, .target = target });
    exe.linkLibC();
    exe.addCSourceFiles(.{ .files = &.{"main.c",  "dynarrays.c"}, .flags = &.{ "-std=gnu2x", "-O2", "-Wall", "-Wextra", "-Wpedantic", "-Wno-unused-parameter", "-Wno-gnu", "-Wno-fixed-enum-extension" } });
    b.installArtifact(exe);

    const run_cmd = b.addRunArtifact(exe);

    run_cmd.step.dependOn(b.getInstallStep());

    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

    const run_step = b.step("run", "Run the app");
    run_step.dependOn(&run_cmd.step);

    const unit_tests = b.addTest(.{
        .root_source_file = .{ .path = "src/main.c" },
        .target = target,
        .optimize = optimization,
    });

    const run_unit_tests = b.addRunArtifact(unit_tests);

    const test_step = b.step("test", "Run unit tests");
    test_step.dependOn(&run_unit_tests.step);
}
