# Maintainer: Krzysztof Demir Kuźniak <krzysztofdemirkuzniak@gmail.com>
pkgname=make-flagslowfix
pkgver=0.1
pkgrel=1
pkgdesc="Automatically adjust make -j based on system specs and project size"
arch=('x86_64')
url="https://github.com/kuznix2011/make-flagslowfix"
license=('GPL-3.0-or-later')
depends=('coreutils')
source=(
Makefile
main.cpp
)
sha256sums=('c45f54564eb83a9b28573af7f6f703cfdb8ed668407bccfee0df35dcbd18af59'
            '440690a586154aeeb82de62d66ee6ee22afa1cec529fd626720db5488cd75b6b')


build() {
    # Build from the project root
    make -C "$srcdir"
}

package() {
    # Install the binary
    install -Dm755 "$srcdir/build/make-flagslowfix" "$pkgdir"/usr/bin/make-flagslowfix
}
