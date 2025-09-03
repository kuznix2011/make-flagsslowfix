# Maintainer: Krzysztof Demir Kuźniak <krzysztofdemirkuzniak@gmail.com>
pkgname=make-flagslowfix
pkgver=0.1
pkgrel=1
pkgdesc="Automatically adjust make -j based on system specs and project size"
arch=('x86_64')
url="https://github.com/kuznix2011/make-flagslowfix"
license=('GPL-3.0-or-later')
depends=('coreutils')
source=()
sha256sums=('SKIP')  # No external sources

build() {
    # Build from the project root
    make -C "$srcdir"
}

package() {
    # Install the binary
    install -Dm755 "$srcdir/build/make-flagslowfix" "$pkgdir"/usr/bin/make-flagslowfix

    # Optional: install README and LICENSE
    install -Dm644 "$srcdir/README.md" "$pkgdir"/usr/share/doc/$pkgname/README.md
    install -Dm644 "$srcdir/LICENSE" "$pkgdir"/usr/share/doc/$pkgname/LICENSE
}
