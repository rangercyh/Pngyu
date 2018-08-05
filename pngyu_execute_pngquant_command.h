#ifndef PNGYU_EXECUTE_PNGQUANT_COMMAND_H
#define PNGYU_EXECUTE_PNGQUANT_COMMAND_H

#include <QString>
#include <QByteArray>
#include <QPair>
#include <QFileInfo>

#include "pngyu_pngquant_option.h"

namespace pngyu
{

QString pngquant_version( const QString &pnqquant_path );

bool is_executable_pnqguant( const QFileInfo pngquant_path );
bool is_executable_optipng( const QFileInfo optipng_path );

QStringList find_executable_pngquant();
QStringList find_executable_optipng();

// execute pnngquant command
// returns <succeed,error_string>
QPair<bool,QString> execute_compress(
    const QString &pngquant_command
    );

// execute pnngquant command with stdio mode
// returns <dst_png_data,error_string>
// if dst_png_data is null, this function has failed
QPair<QByteArray,QString> execute_compress_stdio_mode(
    const QString &pngquant_command,
    const QByteArray &src_png_data
    );

}

#endif // PNGYU_EXECUTE_PNGQUANT_COMMAND_H
